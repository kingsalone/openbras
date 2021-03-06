#ifndef _FLEXBNG_AAA_H_
#define _FLEXBNG_AAA_H_

#include "BaseDefines.h"

#define WFNOS 1

/*用户域别名最大长度*/
#define MAX_DOMAIN_NAME_LEN                   (32)
/*用户名最大长度*/
#define MAX_SUBCRI_NAME_LEN                   (128)
/*用户密码最大长度*/
#define MAX_SUBCRI_PWD_LEN                    (32)
/*MD5加密结果长度*/
#define MD5_RESULT_LENGTH                     (16)

#define CHAP_CHALLENGE_LEN             16
#define CHAP_RESPONSE_LEN              16
#define CHAP_PASSWORD_LEN              (CHAP_RESPONSE_LEN + 1)

#define MS_CHAP_LM_RESPONSE_LEN      (24)  /**<  @brief ms_chap_response的LM-RESPONSE字段,24字节 */
#define MS_CHAP_NT_RESPONSE_LEN      (24)  /**<  @brief ms_chap_response的NT-RESPONSE字段,24字节 */
#define MS_CHAP1_PEER_CHALLEGE_LEN   (8)   /**<  @brief 微软CHAP1挑战字长度8个字节 */

/*MS-CHAP2-REPONSE属性相关长度*/
#define MS_CHAP2_RESPONSE_LEN        (24)  /**<  @brief ms_chap_response,24字节 */
#define MS_CHAP2_PEER_CHALLEGE_LEN   (16)  /**<  @brief 微软CHAP2认证挑战字长度16字节 */
#define MS_CHAP2_RSV_LEN             (8)   /**<  @brief 微软CHAP2认证回应长度 */

/* MS-CHAP-RESPONSE 字段 */
#define MS_CHAP_FLAG_LM_RESPONSE_ONLY      (0)/**<  @brief 微软CHAP2认证回应flag标记之LM-RESPONSE-ONLY */
#define MS_CHAP_FLAG_NT_RESPONSE_FIRST     (1)/**<  @brief 微软CHAP2认证回应flag标记之NT-RESPONSE-FIRST */

/*协议规定MS-CHAP2-Success属性长度，不能修改*/
#define MS_CHAP2_SUC_LEN             (42)  /**<  @brief 微软CHAP V2认证成功返回的回应消息字符串支持的长度 */
#define MS_CHAP_ERR_LEN              (256) /**<  @brief 微软CHAP认证返回的错误回应消息字符串支持的最大长度 */

#define MS_CHAP2_PEER_RESPONSE      ((WORD32)  (42))

#define DSLAM_IDENTIFIER_LEN                  (50)

#define ONU_ID_MAX_LEN       ((WORD32) (24))

#define DSLAM_TYPE_STRING_LEN          (2)/**<  @brief DSLAM设备类型字符串长度 */
#define ONU_PORT_TYPE_STRING_LEN       (3)/**<  @brief ONU设备端口类型字符串长度 */
#define ONU_ACCESS_METHOD_STRING_LEN   (2)/**<  @brief ONU设备接入方法字符串长度 */
#define AGENT_CIR_ID_LENGTH				(128)

#define ANCP_AGENT_ID_LEN            (64)  /**<  @brief DSLAM设备上送的agent-id字符标识支持的最大长度 */

#define AGENT_REMOTE_ID_LENGTH          ANCP_AGENT_ID_LEN

// Authentication Manager
#define AUTHMGR_MAC_LENGTH (6)
#define AUTHMGR_MAX_DOMAIN_SIZE (32)
#define AUTHMGR_MAX_AUTH_RESULT_DESC_SIZE (32)
#define AUTHMGR_MAX_USERNAME_SIZE (32)
#define AUTHMGR_MAX_PASSWD_SIZE AUTHMGR_MAX_USERNAME_SIZE
#define AUTHMGR_MAX_CHALLENGE_SIZE (16)
#define AUTHMGR_MAX_NAS_PORT_ID_SIZE (256)
#define AUTHMGR_MAX_CALLING_STATION_ID_SIZE (64)

typedef enum  {
	 USER_TYPE_START,				//鏃犳晥鐨勭敤鎴风被鍨?
	 USER_TYPE_IPOE = 1,	        //IPOE鐢ㄦ埛绫诲瀷
	 USER_TYPE_PORTAL,
	 USER_TYPE_PPPOE,			    //PPPOE鐢ㄦ埛绫诲瀷 
	 USER_TYPE_L2TP,				//L2TP鐢ㄦ埛绫诲瀷 
	 USER_TYPE_HOST,				//HOST鐢ㄦ埛绫诲瀷
	 USER_TYPE_V6HOST,			    //HOST V6鐢ㄦ埛绫诲瀷
	 USER_TYPE_CGN, 			    //CGN鐢ㄦ埛绫诲瀷
	 USER_TYPE_L3NI,				//涓夊眰鎺ュ叆鐢ㄦ埛绫诲瀷
	 USER_TYPE_L2TP_LNS,			//L2TP LNS鐢ㄦ埛绫诲瀷
	 USER_TYPE_L2TP_LNS_V6, 		//L2TP LNS V6鐢ㄦ埛绫诲瀷
	 USER_TYPE_IPOE_V4, 			//鏀寔鐩稿悓MAC鐢ㄦ埛
	 USER_TYPE_L3HOST,				//L3闈欐�佹帴鍏ョ敤鎴风被鍨?
	 USER_TYPE_RADIUS_PROXY,		//浠ｇ悊鐢ㄦ埛
	 USER_TYPE_END 				    //鏃犳晥鐨勭敤鎴风被鍨?  	 
}SessionUserType;		

typedef enum {
	AIM_REQ_TYPE_AUTHEN,
    AIM_REQ_TYPE_AUTHOR
}AIM_REQ_TYPE;

typedef enum {
    AUTH_PAP,
    AUTH_CHAP,
    AUTH_MSCHAP,
    AUTH_EAP
}AIM_AUTH_TYPE;

/**  鐢ㄦ埛鎺ュ叆绔彛绫诲瀷鍊煎畾涔夛紝鍏蜂綋鍙傝RFC2865 */
typedef enum RADIUS_NAS_PORT_TYPE_VALUE
{
    RADIUS_NAS_PORT_TYPE_ASYNC               = 0, /**<  @brief ASYNC鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_SYNC                = 1, /**<  @brief SYNC鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ISDN_SYNC           = 2, /**<  @brief ISDN-SYNC鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ISDN_ASYNC_V120     = 3, /**<  @brief ISDN-ASYNC-V120鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ISDN_ASYNC_V110     = 4, /**<  @brief ISDN-ASYNC-V110鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_VIRTUAL             = 5, /**<  @brief VIRTUAL鎺ュ叆绔彛绫诲瀷锛宭2tp鐢ㄦ埛浣跨敤 */
    RADIUS_NAS_PORT_TYPE_PIAFS               = 6, /**<  @brief PIAFS鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_HDLC_CLEAR_CHANNEL  = 7, /**<  @brief HDLC-CLEAR-CHANNEL鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_X25                 = 8, /**<  @brief X25鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_X75                 = 9, /**<  @brief X75鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_G3FAX               = 10,/**<  @brief G3FAX鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_SDSL                = 11,/**<  @brief SDSL鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ADSL_CAP            = 12,/**<  @brief ADSL-CAP鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ADSL_DMT            = 13,/**<  @brief ADSL-DMT鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_IDSL                = 14,/**<  @brief IDSL鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_ETHERNET            = 15,/**<  @brief ETHERNET鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_XDSL                = 16,/**<  @brief XDSL鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_CABLE               = 17,/**<  @brief CABLE鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_WIRELESS            = 18,/**<  @brief WIRELESS鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_WIRELESS_IEEE802_11 = 19,/**<  @brief WIRELESS-IEEE802-11鎺ュ叆绔彛绫诲瀷 */
    RADIUS_NAS_PORT_TYPE_MAX                 = 20 /**<  @brief 鎺ュ叆绔彛绫诲瀷鏈�澶у�硷紝鏃犳剰涔?*/
}RADIUS_NAS_PORT_TYPE_VALUE;

/**  鐢ㄦ埛鎺ュ叆鍗忚鍊煎畾涔夛紝鍏蜂綋鍙傝RFC2865 */
typedef enum RADIUS_FRAMED_PROTOCOL_VALUES
{
    FRAMED_PROTOCOL_PPP      = 1,/**<  @brief PPP鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_SLIP     = 2,/**<  @brief SLIP鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_ARAP     = 3,/**<  @brief ARAP鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_GANDALF  = 4,/**<  @brief GANDALF鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_XYLOGICS = 5,/**<  @brief XYLOGICS鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_X75      = 6,/**<  @brief X75鎺ュ叆鍗忚 */
    FRAMED_PROTOCOL_MAX      = 7 /**<  @brief 鎺ュ叆鍗忚鏈�澶у�硷紝鏃犳剰涔?*/
}RADIUS_FRAMED_PROTOCOL_VALUES;

/**  RADIUS 鏈嶅姟绫诲瀷鍊煎畾涔夛紝鍏蜂綋鍙傝RFC2865 */
typedef enum RADIUS_SERVICE_TYPE_VALUES
{
    SERVICE_TYPE_LOGIN                   = 1, /**<  @brief LOGIN鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_FRAMED                  = 2, /**<  @brief FRAMED鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_CALLBACK_LOGIN          = 3, /**<  @brief CALLBACK-LOGIN鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_CALLBACK_FRAMED         = 4, /**<  @brief CALLBACK-FRAMED鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_OUTBOUND                = 5, /**<  @brief OUTBOUND鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_ADMINISTRATIVE          = 6, /**<  @brief ADMINISTRATIVE鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_NAS_PROMPT              = 7, /**<  @brief NAS-PROMPT鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_AUTHENTICATE_ONLY       = 8, /**<  @brief AUTHENTICATE-ONLY鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_CALLBACK_NAS_PROMPT     = 9, /**<  @brief CALLBACK-NAS-PROMPT鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_CALL_CHECK              = 10,/**<  @brief CALL-CHECK鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_CALLBACK_ADMINISTRATIVE = 11,/**<  @brief CALLBACK-ADMINISTRATIVE鏈嶅姟绫诲瀷 */
    SERVICE_TYPE_MAX                     = 12 /**<  @brief 鏈嶅姟绫诲瀷鏈�澶у�硷紝鏃犳剰涔?*/
}RADIUS_SERVICE_TYPE_VALUES;

/**
*   用户密码
*/
typedef struct SUBSCRI_PWD
{
    CHAR    str[MAX_SUBCRI_PWD_LEN];      /**<@brief  密码 */
} SUBSCRI_PWD;

typedef struct PAP_AUTH_INFO
{
    SUBSCRI_PWD subPwd;
} PAP_AUTH_INFO;

/*CHAP认证信息*/
typedef struct
{
    CHAR    str[CHAP_PASSWORD_LEN + 3];/*为保持4字节对齐，将此处修改*/
} CHAP_PASSWORD;


typedef struct
{
    CHAR    str[CHAP_CHALLENGE_LEN];
} CHANLLENGE;

typedef struct CHAP_AUTH_INFO
{
    CHAP_PASSWORD   chapPwd;
    BYTE            chapId;       /**<@brief CHAP认证时的1字节CHAP-ID */
    BYTE            reserved[3];
    CHANLLENGE      challenge;
} CHAP_AUTH_INFO;
typedef struct MS_CHAPV1_PASSWORD
{
    char  str[MS_CHAP_NT_RESPONSE_LEN];
} MS_CHAPV1_PASSWORD;
typedef struct MS_CHAPV1_CHANLLENGE
{
    char  str[MS_CHAP1_PEER_CHALLEGE_LEN];
} MS_CHAPV1_CHANLLENGE;

typedef struct MS_CHAPV2_PASSWORD
{
    char  str[MS_CHAP_NT_RESPONSE_LEN];
} MS_CHAPV2_PASSWORD;

typedef struct MS_CHAPV1_AUTH_INFO
{
    MS_CHAPV1_PASSWORD LMResp;
    MS_CHAPV1_PASSWORD NTResp;
    MS_CHAPV1_CHANLLENGE        MSChapV1Challenge;
    BYTE           ChapID;           /* CHAP认证时的1字节CHAP-ID 需要传送给radius封装属性用*/
    BYTE NTFlag;        /* If 1, ignore the LM response field */
    BYTE  Idle[2];
} MS_CHAPV1_AUTH_INFO;

typedef struct MS_CHAPV2_AUTH_INFO
{
    MS_CHAPV2_PASSWORD           ChapV2Resp;
    CHANLLENGE                             MSChapV2Challenge;
    CHANLLENGE                              peerCHAPV2Challenge;
    BYTE      peerCHAPV2Response[MS_CHAP2_PEER_RESPONSE ];
    BYTE           ChapID;          /* CHAP认证时的1字节CHAP-ID 需要传送给radius封装属性用*/
    BYTE   Idle;
} MS_CHAPV2_AUTH_INFO;

/**
*   用户定位信息
*/
typedef struct USER_ANI_PORT_INFO
{
    CHAR    accNodeIdentifier[DSLAM_IDENTIFIER_LEN +1]; /**<@brief 接入节点标识(如DSLAM设备)，字符串中间不能有空格 */
    BYTE    aniXpiEnable;          /**<@brief 0没有，1有 */
    WORD16  aniXpi;                /**<@brief 可选项     */
    WORD16  aniXci;                /**<@brief 可选项ANI_XPI.ANI_XCI，主要是携带CPE侧的业务信息，
                                   用于标识未来的业务类型需求， 如在多PVC应用场合下可标识具体的业务*/
    BYTE    aniRack;               /**<@brief 接入节点机架号（如支持紧耦合的DSLAM设备） 0~15  */
    BYTE    aniFrame;              /**<@brief 接入节点机框号0~31  */
    BYTE    aniSlot;               /**<@brief 接入节点槽号0~127   */
    BYTE    aniSubSlot;            /**<@brief 接入节点子槽号0~31  */
    BYTE    aniPort;               /**<@brief 接入节点端口号0~255 */
    BYTE  ONU_Slot;
    BYTE  ONU_Subslot;
    BYTE  ONUPort_ID;
    WORD32 dslam_port_type;
    BYTE  AniONU_ID[ONU_ID_MAX_LEN];
    BYTE  ONUPortType[ONU_PORT_TYPE_STRING_LEN];/*ptm|atm|eth*/
    WORD16  ONUPortXpi;
    WORD16  ONUPortXci;
    BYTE  ONUAccessMethod[ONU_ACCESS_METHOD_STRING_LEN];/*{EP|GP}：表示该用户采用的接入技术；EP表示EPON技术，GP表示GPON技术。*/
    BYTE   AgentCirId[AGENT_CIR_ID_LENGTH];
    WORD16 CirIdLength;
    WORD16 RemoteIdLength;
    BYTE   AgentRemoteId[AGENT_REMOTE_ID_LENGTH];
    WORD32 PortLocType;
    CHAR   cDslamType[DSLAM_TYPE_STRING_LEN];/*AD|V2*/
} USER_ANI_PORT_INFO;

/**
 *  供各业务使用电路信息类型
 */
typedef struct T_BRAS_VCC_CIR_ID
{               
    BYTE                    panel;             /**< @brief 槽位号 */
    BYTE                    subPanel;          /**< @brief 子卡号 */
    WORD16                  porttype;          /**<@brief  端口类型*/ 
    WORD32                  port;              /**< @brief 端口号 */
    WORD16                  vlanId;            /**< @brief vlan id */
    WORD16                  secVlanId;         /**< @brief second-vlan id, 双层vlan有效 */
    WORD32                  outIdx;            /**< @brief 出接口索引 */
    WORD16                  qinqEtherType;     /**< @brief qinq以太类型 */
    WORD16                  reserve2;          /* padding bits */
    WORD32                  vccIndex;          /**< @brief vcc接口索引 */
    WORD32                  vbuiIndex;         /**< @brief vbui接口索引 */
    WORD32                  L3IfIndex;         /**< @brief l3-access接口索引 */
    WORD32                  protocolType;      /**< @brief 接入协议类型 */
} BRAS_VCC_CIR_ID;


typedef union AuthInfo
{
    PAP_AUTH_INFO   pap;    /**<@brief 用户的PAP 密码信息*/
    CHAP_AUTH_INFO  chap;   /**<@brief 用户的CHAP密码信息*/
    MS_CHAPV1_AUTH_INFO mschapV1;/**<@brief 用户的MSCHAPV1密码信息*/
    MS_CHAPV2_AUTH_INFO mschapV2;/**<@brief 用户的MSCHAPV2密码信息*/
} AuthInfo;

typedef struct _Auth_Request {	
	BYTE user_type;	    // 鐢ㄦ埛绫诲瀷,pppoe ipoe绛?
    BYTE reserved[3];
	BYTE aaaRequestType;
	BYTE authtype;
	BYTE chapid;
	BYTE nasPortType;
    WORD16 session;
    BYTE mac[AUTHMGR_MAC_LENGTH];  // 鐢ㄦ埛鐨凪AC鍦板潃
    CHAR username[AUTHMGR_MAX_USERNAME_SIZE];  // username鍜寀serpasswd绾﹀畾鏈�鍚庝竴涓瓧鑺傚瓨鏀?锛屽嵆鏈�澶ф敮鎸佺殑鐢ㄦ埛鍚嶅拰瀵嗙爜涓?AUTHMGR_MAX_USERNAME_SIZE - 1)瀛楄妭
    CHAR userpasswd[AUTHMGR_MAX_PASSWD_SIZE];  // 鍦–HAP璁よ瘉涓紝userpasswd[0]...userpasswd[15]杩?6涓瓧鑺傚鐢ㄦ潵瀛樻斁鐢ㄦ埛鍥炲鐨剅esponse
    CHAR domain[AUTHMGR_MAX_DOMAIN_SIZE];
	BYTE challenge[AUTHMGR_MAX_CHALLENGE_SIZE];
	CHAR nasPortID[AUTHMGR_MAX_NAS_PORT_ID_SIZE];
	CHAR callingStationId[AUTHMGR_MAX_CALLING_STATION_ID_SIZE];
	WORD32 framedProtocol;
	WORD32 serviceType;
	WORD16 nasVlan;
	WORD16 nasPort;
//#ifdef WFNOS
    WORD32              subIp;                  /**< @brief 用户的地址 */
    USER_ANI_PORT_INFO aniInfo;
    BRAS_VCC_CIR_ID vccinfo;
    AuthInfo auth_info;
//#endif
}Auth_Request;

typedef struct _Auth_Response {
    WORD16 session;
    BYTE   mac[AUTHMGR_MAC_LENGTH];
    WORD32 vrf;
    WORD32 user_ip;
    CHAR   domain[AUTHMGR_MAX_DOMAIN_SIZE];
    WORD32 authResult; // 0琛ㄧず璁よ瘉鎴愬姛锛岄潪0琛ㄧず澶辫触
    CHAR   authResultDesc[AUTHMGR_MAX_AUTH_RESULT_DESC_SIZE]; // 璁よ瘉缁撴灉鎻忚堪锛屾瘮濡?authentication success"/"authentication fail"
    WORD32 subscriberIP; // radius鍒嗛厤缁檚ubsriber鐨処P锛屼富鏈哄簭
    WORD32 subscriberIPMask;  // Subscribe IP netmask assigned by radius, in host byte order. Used in IPOE.
    WORD32 leaseTime;
    WORD32 gatewayaddr;  // Relay router/gateway address assigned by radius, in host byte order. Used in IPOE.
    WORD32 primaryDNS;  // radius鍒嗛厤缁檚ubsriber鐨凱rimary DNS IP锛屼富鏈哄簭
    WORD32 secondaryDNS; // radius鍒嗛厤缁檚ubsriber鐨凷econdary DNS IP锛屼富鏈哄簭
}Auth_Response;

// Session Manager
#define SESSION_MGR_MAX_USERNAME_SIZE (32)
#define SESSION_MGR_MAC_SIZE (6)
#define SESSION_MGR_MAX_DOMAIN_SIZE (32)

typedef struct _Session_User_Ex {
    WORD16 session;
    BYTE  mac[SESSION_MGR_MAC_SIZE];
	BYTE  user_type;	         // 鐢ㄦ埛绫诲瀷,pppoe ipoe绛?
	BYTE  access_type; 	         // 鐢ㄦ埛鎺ュ叆绫诲瀷 ipv4 ipv6鎴杁ual stack
	BYTE  auth_type;	         // 璁よ瘉绫诲瀷濡俽adius璁よ瘉
	BYTE  auth_state;			 // 鐢ㄦ埛璁よ瘉鐘舵�?
	CHAR  user_name[SESSION_MGR_MAX_USERNAME_SIZE];
	CHAR  domain[SESSION_MGR_MAX_DOMAIN_SIZE];	
    WORD32   vrf;
    WORD32   user_ip;            // radius鍒嗛厤缁檚ubsriber鐨処P锛屼富鏈哄簭
    WORD32   primary_dns;        // radius鍒嗛厤缁檚ubsriber鐨凱rimary DNS IP锛屼富鏈哄簭
    WORD32   secondary_dns;      // radius鍒嗛厤缁檚ubsriber鐨凷econdary DNS IP锛屼富鏈哄簭   
	WORD32   pool_id;		     // ip pool id鍙?
	WORD32   intern_vlan;		 // 鎺ュ叆鍐呭眰vlan鍙?
	WORD32   extern_vlan;		 // 鎺ュ叆澶栧眰vlan鍙?
} Session_User_Ex;

typedef struct _Sm_Kick_User {
    WORD16 session;
    WORD32 userip;
    WORD32   vrf;
    BYTE mac[SESSION_MGR_MAC_SIZE];
}Sm_Kick_User;

typedef struct _Session_Offline {
    WORD16 user_type;
	WORD16 session;
	BYTE  mac[SESSION_MGR_MAC_SIZE];
}Session_Offline;

typedef struct {
    WORD32 result;
	WORD16 session;
	BYTE mac[SESSION_MGR_MAC_SIZE];
}UM_RESPONSE;

#endif//_FLEXBNG_AAA_H_
