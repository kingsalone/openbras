/***********************************************************************
 * Copyright (C) 2014, Nanjing WFNEX Technology Co., Ltd 
**********************************************************************/
#include "CPortalFakeServer.h"
#include "CPortalManager.h"
#include "CPortalServerManager.h"
#include "CPortalServerChannel.h"
#include "CPortalUserMgr.h"
#include "CPortalConfig.h"

CPortalHTTPChannel::CPortalHTTPChannel()
    :CTCPTransport(ACE_Reactor::instance())
    ,m_id(0)
    ,m_pserver(NULL)
{
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::CPortalHTTPChannel_1\n")); 
}

CPortalHTTPChannel::CPortalHTTPChannel(uint32_t id, CPortalFakeServer *pserver)
    :CTCPTransport(ACE_Reactor::instance())
    ,m_id(id)
    ,m_pserver(pserver)
{
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::CPortalHTTPChannel_2\n")); 
}

CPortalHTTPChannel::~CPortalHTTPChannel()
{
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::~CPortalHTTPChannel\n")); 

    //if (m_pserver)
    //{
    //    m_pserver->RemoveChannel(this);
    //}
}

void CPortalHTTPChannel::SetPortalServer(CPortalFakeServer *pserver)
{
    m_pserver = pserver;
}
/**********************************************************************************/
/*原重定向http报文格式：context1+[?UasIPName=UasIP&UserIPName=UserIP]+context3     */
/*江苏移动重定向http报文格式：context1+[?wlanacname=uas_id&wlanuserip=UserIP]+context3
   context1:
   HTTP/1.0 302 Moved Temporarily
   Content-Type: text/html
   Location:http://www.portal.com?wlanacname=uas_id&wlanuserip=UserIP

   
   context3:
   Content-Length: 0
   Date: Wed, 04 Sep 2002 02:28:46 GMT
   Server: Tomcat Web Server/3.3.1 Final ( JSP 1.1; Servlet 2.2 )
   */
/*********************************************************************************/

size_t CPortalHTTPChannel::OnHandleMessage(const ACE_Message_Block &aData)
{
    std::string str;
    std::string str1="HTTP/1.1 302 Moved Temporarily\r\n"
        "Content-Type: text/html\r\n"
        "Cache-Control: no-cache\r\n"
        "Location: ";
    
    std::string poststr="Content-Type: text/html\r\n"
        "Content-Length: 0\r\n\r\n";

    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::OnHandleMessage,data size=%d\n",aData.length())); 

    if (m_pserver == NULL)
    {
        return aData.length(); 
    }

    PortalServerCfg *pserverch = (m_pserver->GetPortalConfig()).GetRedirectCfg(0);
    if (pserverch)
    {
        ACE_INET_Addr peeraddr = this->GetRemoteAddress();
        ACE_TCHAR addrstr[BUFSIZ]={0};
        peeraddr.addr_to_string (addrstr, sizeof addrstr);
        ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::OnHandleMessage, peer client=%s\n", addrstr));

        PortalServerCfg &cfg = *pserverch;
        char hoststr[MAXHOSTNAMELEN+1];
        peeraddr.get_host_addr(hoststr, MAXHOSTNAMELEN+1);
        std::string hoststdstr=std::string(hoststr,strlen(hoststr));
        std::string url = std::string(cfg.url,strlen(cfg.url));
        
        str=str1+url+"?wlanuserip="+hoststdstr+"\r\n"+poststr;

        ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalHTTPChannel::OnHandleMessage redirecturl=%s\n",str.c_str())); 
        SendMessage((char*)str.c_str(), str.size());
    }
    //return SendMessage(aData);
    //::send(this->get_handle(),(char*)str.c_str(), str.size(),0);

    return aData.length();
}

void CPortalHTTPChannel::OnRcvBufferOverFlow(size_t maxbuffersize)
{
    
}

void CPortalHTTPChannel::OnConnected()
{
}
    
CPortalFakeServer::CPortalFakeServer(CPortalManager &mgr)
    :m_mgr(mgr)
{
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalFakeServer::CPortalFakeServer\n")); 
}
CPortalFakeServer::~CPortalFakeServer()
{
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalFakeServer::~CPortalFakeServer\n")); 
}

int CPortalFakeServer::StartListen(const ACE_INET_Addr &httplistenip)
{

    ACE_TCHAR localaddr_str[BUFSIZ]={0};
    httplistenip.addr_to_string (localaddr_str, sizeof localaddr_str);
    ACE_DEBUG ((LM_DEBUG,"(%P|%t) CPortalFakeServer::StartListen, httplistenip=%s\n", localaddr_str));

    int flags = 0;
    ACE_SET_BITS (flags, ACE_NONBLOCK);
    if (this->open (httplistenip, ACE_Reactor::instance(), flags) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%t) %p\n"),
                  ACE_TEXT ("Unable to open server service handler")));

      return -1;
    }
    return 0;
}

void CPortalFakeServer::StopListen()
{
    UNBINDVSType::iterator it2 = m_UnBindVSs.begin();
    while(it2 != m_UnBindVSs.end())
    {
        it2 = m_UnBindVSs.erase(it2);
    }

    ACCEPTOR::close();
}


int CPortalFakeServer::accept_svc_handler (CPortalHTTPChannel *handler)
{
    ACE_DEBUG ((LM_DEBUG,"CPortalFakeServer::accept_svc_handler\n"));
    int result = this->ACCEPTOR::accept_svc_handler (handler);

    if (result != 0)
    {
        if (errno != EWOULDBLOCK)
            ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%t) %p\n"),
                  ACE_TEXT ("Unable to accept connection")));

        return result;
    }

    ACE_DEBUG ((LM_DEBUG,
        ACE_TEXT ("(%t) Accepted connection.  ")
        ACE_TEXT ("Stream handle: <%d>\n"),
        handler->get_handle ()));


    //handler->open(NULL);

    //if (AddChannel(handler) == -1)
    //{
    //    return -1;
    //}

    return result;
}

int CPortalFakeServer::make_svc_handler (CPortalHTTPChannel *&sh)
{
    ACE_DEBUG ((LM_DEBUG,"CPortalFakeServer::make_svc_handler\n"));
    CPortalHTTPChannel *ih;
    ACE_NEW_RETURN (ih, CPortalHTTPChannel(m_nHttIDBase++,this), 0);

    sh = ih;
    
    return 0;
}

int CPortalFakeServer::AddChannel(CPortalHTTPChannel *pvs)
{
    if (pvs == NULL)
    {
        return -1;
    }

    uint32_t id = pvs->GetID();
    CCmAutoPtr<CPortalHTTPChannel> channel(pvs);

    m_UnBindVSs[id] = channel;

    return 0;
}

int CPortalFakeServer::RemoveChannel(CPortalHTTPChannel *pvs)
{
    m_UnBindVSs.erase(pvs->GetID());
    return 0;
}

CPortalHTTPChannel *CPortalFakeServer::FindChannel(int handler)
{
    if (handler <=0)
    {
        return NULL;
    }
    CCmAutoPtr<CPortalHTTPChannel> &channel = m_UnBindVSs[handler];
    return channel.Get();
}
CPortalConfig &CPortalFakeServer::GetPortalConfig()
{
    return m_mgr.GetPortalConfig();
}


