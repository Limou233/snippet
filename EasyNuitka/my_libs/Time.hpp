/*
Coding:UTF-8
@Author:Limou233[github.com/limou233]
Compiler:MinGW-W64-builds-4.3.5
*/
#ifndef TIME_HPP
#define TIME_HPP 1

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

string getCurrentTime(const char* __Fmt="%Y-%m-%d %H:%M:%S"){// (const char*:日期格式) -> string:格式化的日期
    //from CodeGeeX Pro             year-month-day-hour-minute-second
    // 获取当前时间戳并转换为 time_t 类型
    auto NowTime_T=chrono::system_clock::to_time_t(chrono::system_clock::now());
    // 转换为 tm 结构体
    tm* now_tm=localtime(&NowTime_T);
    // 使用 stringstream 存储转换后的时间戳
    stringstream StrS;
    StrS<<put_time(now_tm,__Fmt);

    return StrS.str();
}

#endif /*TIME.HPP*/