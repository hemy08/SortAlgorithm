//
// Created by Hemy08 on 2019/1/27.
//

#include "Debug.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdarg.h>

uchar_t* g_ucLogLevel[LOG_LEV_BUTT] = {
        "LEVEL_DEBUG",
        "LEVEL_INFO",
        "LEVEL_NOTIFICATION",
        "LEVEL_WARNING",
        "LEVEL_ERROR",
        "LEVEL_CRITICAL",
        "LEVEL_ALERT",
        "LEVEL_EMERGENCY"
};

FILE* g_fpLogFile = (FILE*)null_ptr;
uchar_t g_aclogFullName[MAX_FULL_PATH_LEN] = "./debug_log.log";
uint32_t  g_logRecodeMode = LOG_FILE|LOG_FUNC|LOG_TIME|LOG_LEVE|LOG_LINE;

/*
 * 设置日志文件路径
 */
void LogSetLogFileName(uchar_t *pcFileNema)
{
    if ((NULL != pcFileNema) && (0 != strlen(pcFileNema)))
    {
        strcpy_s(g_aclogFullName,MAX_FULL_PATH_LEN,pcFileNema);
    }
}

/*
 * 获取系统当前的时间，便于日志记录打印
 */
void LogSetRecordMode(uint32_t uilogMode)
{
    g_logRecodeMode = uilogMode;
}
/*
 * 获取系统当前的时间，便于日志记录打印
 */
void LogServerCurrentTime(uchar_t *pcTimeStr)
{
    struct timeval d_stTv;
    struct tm * d_stTm;
    time_t  t;
    (void)gettimeofday (&d_stTv, NULL);
    time(&t);
    d_stTm = localtime(&t);
    (void)sprintf(pcTimeStr, "%02d_%02d_%02d-%02d:%02d:%02d.%06lu ",
                  (1900 + d_stTm->tm_year),
                  (1 + d_stTm->tm_mon),
                  d_stTm->tm_mday,
                  d_stTm->tm_hour,
                  d_stTm->tm_min,
                  d_stTm->tm_sec,
                  d_stTv.tv_usec);

    return;
}

/*
 * 日志打印，写日志文件
 */
void LogServerRecordLog(const uchar_t* pcFile, const uchar_t* pcFunc,uint32_t uiLineNo, uint32_t uiLogLev, const uchar_t* pcLogFmt, ...)
{

    va_list ArgList;
    uchar_t    acLogTime[MAX_LOG_TM_STR_LEN + 1] = {0};
    uchar_t    szLogFmt[MAX_SZBUF_LEN + 1] = "";
    uchar_t    szBufTemp[MAX_SZBUF_LEN + 1] = "";
    uchar_t    szBuffer[MAX_SZBUF_LEN + 1] = "";
    uchar_t    *pcLogBuff=null_ptr;

    if (LOG_LEV_BUTT <= uiLogLev)
    {
        return;
    }

    if((FILE *)null_ptr == g_fpLogFile)
    {
        g_fpLogFile = fopen(g_aclogFullName, "a+");
        if((FILE *)null_ptr == g_fpLogFile)
        {
            return;
        }
    }

    va_start(ArgList, pcLogFmt);
    vsprintf_s(szLogFmt, MAX_SZBUF_LEN, pcLogFmt, ArgList);
    va_end(ArgList);

    if (g_logRecodeMode & LOG_TIME)
    {
        LogServerCurrentTime(acLogTime);
        sprintf_s(szBufTemp,MAX_SZBUF_LEN,"%s- ",acLogTime);
    }

    if (g_logRecodeMode & LOG_LEVE)
    {
        sprintf_s(szBuffer,MAX_SZBUF_LEN, "%s %s", szBufTemp, g_ucLogLevel[uiLogLev]);
        strcpy_s(szBufTemp,MAX_SZBUF_LEN,szBuffer);
        memset(szBuffer,0,MAX_SZBUF_LEN);
    }

    if (g_logRecodeMode & LOG_FILE)
    {
        sprintf_s(szBuffer,MAX_SZBUF_LEN, "%s %s", szBufTemp, pcFile);
        strcpy_s(szBufTemp,MAX_SZBUF_LEN,szBuffer);
        memset(szBuffer,0,MAX_SZBUF_LEN);
    }

    if (g_logRecodeMode & LOG_FUNC)
    {
        sprintf_s(szBuffer,MAX_SZBUF_LEN, "%s %s", szBufTemp, pcFunc);
        strcpy_s(szBufTemp,MAX_SZBUF_LEN,szBuffer);
        memset(szBuffer,0,MAX_SZBUF_LEN);
    }

    if (g_logRecodeMode & LOG_LINE)
    {
        sprintf_s(szBuffer,MAX_SZBUF_LEN, "%s:%d", szBufTemp, uiLineNo);
        strcpy_s(szBufTemp,MAX_SZBUF_LEN,szBuffer);
        memset(szBuffer,0,MAX_SZBUF_LEN);
    }

    strcpy_s(szBuffer,MAX_SZBUF_LEN,szBufTemp);

    fprintf(g_fpLogFile, "%s %s\n",szBuffer, szLogFmt);
    fflush(g_fpLogFile);

    (void)va_end(ArgList);
    return;
}
