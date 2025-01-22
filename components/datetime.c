/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

const char *
datetime(const char *fmt)
{
	static char datetime[128];
    struct tm *tm_info;
    time_t timer;

    time(&timer);
    tm_info = localtime(&timer);

    int year = tm_info->tm_year + 1900;  // 获取公历年份
    int minguo_year = year - 1911;       // 计算民国年份

    // 使用 strftime 获取格式化时间，首先获取年月日等信息
    strftime(datetime, sizeof(datetime), "%m月%d日 週%u %T", tm_info);

    // 用 snprintf 构建民国日期字符串，替换公历年份为民国年份
    char temp[128];
    snprintf(temp, sizeof(temp), "民國%d年%s", minguo_year, datetime);  // 将公历年份替换为民国年份
    snprintf(datetime, sizeof(datetime), "%s", temp);

    return datetime;
}
//const char *
//datetime(const char *fmt)
//{
//	time_t t;
//
//	t = time(NULL);
//	if (!strftime(buf, sizeof(buf), fmt, localtime(&t))) {
//		warn("strftime: Result string exceeds buffer size");
//		return NULL;
//	}
//
//	return buf;
//}
