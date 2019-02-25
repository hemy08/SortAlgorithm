//
// Created by Hemy08 on 2019/1/27.
//

#ifndef __LOGGERC_DEBUG_H__
#define __LOGGERC_DEBUG_H__

typedef char uchar_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long ulong_t;
typedef unsigned int bool_t;

#ifndef null
#define null 0
#endif
#ifndef null_ptr
#define null_ptr ((void*)0)
#endif
#ifndef null_byte
#define null_byte (uint8_t)0xFF
#endif
#ifndef null_byte_word
#define null_byte_word (uint16_t)0xFFFF
#endif
#ifndef null_byte_dword
#define null_byte_dword (uint32_t)0xFFFFFFFF
#endif

#define MAX_PATH_LEN 512   //日志文件路径长度
#define MAX_FILE_NAME_LEN 64   //日志文件名长度
#define MAX_FULL_PATH_LEN (MAX_PATH_LEN+MAX_FILE_NAME_LEN)
#define MAX_SZBUF_LEN  1024  //日志文件单次打印缓存大小
#define MAX_LOG_TM_STR_LEN 32 //时间字符串长度


typedef enum {
    LOG_LEV_DEBUG,  //调试
    LOG_LEV_INFO,   //信息提示
    LOG_LEV_NOTIFICATION, //通知
    LOG_LEV_WARNING, //警告
    LOG_LEV_ERROR,   //错误
    LOG_LEV_CRITICAL, //严重
    LOG_LEV_ALERT, //报警
    LOG_LEV_EMERGENCY, //紧急
    LOG_LEV_BUTT
}SYS_LOG_LEVEL;

typedef enum {
    LOG_TIME = 0X0001,
    LOG_FILE = 0X0002,
    LOG_FUNC = 0X0004,
    LOG_LINE = 0X0008,
    LOG_LEVE = 0X0010,
    LOG_FMT  = 0X0020,
    LOG_ALL  = 0X003F
}SYS_LOG_MODE;

/*
 * 设置日志文件路径
 */
void LogSetLogFileName(uchar_t *pcFileNema);
/*
 * 获取系统当前的时间，便于日志记录打印
 */
void LogSetRecordMode(uint32_t uilogMode);
/*
 * 获取系统当前的时间，便于日志记录打印
 */
void LogServerCurrentTime(uchar_t *pcTimeStr);
/*
 * 日志打印，写日志文件
 */
void LogServerRecordLog(const uchar_t* pcFile, const uchar_t* pcFunc,uint32_t uiLineNo, uint32_t uiLogLev, const uchar_t* pcLogFmt, ...);

#define LOG_RECORD(logLev, fmt, ...) \
    LogServerRecordLog(__FILE__, __FUNCTION__,(uint32_t)__LINE__, (uint32_t)logLev, fmt, ##__VA_ARGS__)

#endif //__LOGGERC_DEBUG_H__
