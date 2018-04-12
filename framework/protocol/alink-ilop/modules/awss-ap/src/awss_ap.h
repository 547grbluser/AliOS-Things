/*
 * Copyright (c) 2014-2016 Alibaba Group. All rights reserved.
 *
 * Alibaba Group retains all right, title and interest (including all
 * intellectual property rights) in and to this computer program, which is
 * protected by applicable intellectual property laws.  Unless you have
 * obtained a separate written license from Alibaba Group., you are not
 * authorized to utilize all or a part of this computer program for any
 * purpose (including reproduction, distribution, modification, and
 * compilation into object code), and you must immediately destroy or
 * return to Alibaba Group all copies of this computer program.  If you
 * are licensed by Alibaba Group, your rights to utilize this computer
 * program are limited by the terms of that license.  To obtain a license,
 * please contact Alibaba Group.
 *
 * This computer program contains trade secrets owned by Alibaba Group.
 * and, unless unauthorized by Alibaba Group in writing, you agree to
 * maintain the confidentiality of this computer program and related
 * information and to not disclose this computer program and related
 * information to any other person or entity.
 *
 * THIS COMPUTER PROGRAM IS PROVIDED AS IS WITHOUT ANY WARRANTIES, AND
 * Alibaba Group EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED,
 * INCLUDING THE WARRANTIES OF MERCHANTIBILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE, AND NONINFRINGEMENT.
 */

#ifndef __AWSS_AP__H__
#define __AWSS_AP__H__

#include <unistd.h>
#include "iot_import_product.h"
#include "awss_devlist.h"

#ifdef __cplusplus
extern "C" {
#endif


#define AWSS_SIGN_RANDOM_LEN         4
#define AWSS_VRSION_LEN              64
#define AWSS_DEVICE_SIGN_LEN         32
#define AWSS_DEVICE_MAC_LEN          17
#define AWSS_DEVICE_IP_LEN           15
#define AWSS_DEVICE_RAND_LEN         32

#define AWSS_SUCCESS                (0)   /* Successful */
#define AWSS_ERROR                  (-1)  /* Failue */

#define CALL_FUCTION_FAILED         "Call function \"%s\" failed\n"
#define RET_FAILED(ret)  (ret != AWSS_SUCCESS)
#define RET_GOTO(Ret,gotoTag,strError, args...)         \
      {\
        if ( RET_FAILED(Ret) )    \
        {   \
            log_warning(strError, ##args); \
            goto gotoTag; \
        }\
      }

#define RET_FALSE(Ret,strError,args...)         \
    {\
        if ( RET_FAILED(Ret) )    \
        {   \
            log_warning(strError, ##args); \
            return false; \
        }\
     }

#define RET_RETURN(Ret,strError,args...)         \
    {\
        if ( RET_FAILED(Ret) )    \
        {   \
            log_warning(strError, ##args); \
            return Ret; \
        }\
    }
#define RET_LOG(Ret,strError,args...)         \
    {\
        if ( RET_FAILED(Ret) )    \
        {   \
            log_warning(strError, ##args); \
        }\
    }

#define PTR_RETURN(Pointer,Ret,strError,args...)         \
    {\
        if ( !Pointer)    \
        {   \
            log_err(strError, ##args); \
            return Ret; \
        }\
     }

#define PTR_FALSE(Pointer,strError,args...)         \
    {\
        if ( !Pointer)    \
        {   \
            log_warning(strError, ##args); \
            return FALSE; \
        }\
    }
#define PTR_LOG(Pointer,strError,args...)         \
    {\
        if ( !Pointer)    \
        {   \
            log_warning(strError, ##args); \
        }\
    }


#define PTR_GOTO(Pointer, gotoTag, strError, args...)         \
    {\
        if ( !Pointer)    \
        {   \
            log_warning(strError, ##args); \
            goto gotoTag; \
        }\
     }

#define POINTER_RETURN(Pointer,strError,args...)         \
    {\
        if ( !Pointer)    \
        {   \
            log_warning(strError, ##args); \
            return Pointer; \
        }\
     }

typedef struct {
    char device_name[DEVICE_NAME_MAXLEN + 1];
    char product_key[PRODUCT_KEY_MAXLEN + 1];
    uint32_t period;
}dev_id_t;


int awss_new_device_discovery(dev_info_t *new_dev);
int awss_checkin_device(const char *product_key, const char *device_name, uint32_t period);
int awss_push_whitelist(dev_id_t white_list[], uint8_t length);
void awss_attach_device(dev_info_t *dev_info);

int awss_ap_init(void);
void awss_ap_exit(void);

#ifdef __cplusplus
}
#endif
#endif

