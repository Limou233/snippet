/*
Coding:UTF-8
@Author:Limou233[github.com/limou233]
Compiler:MinGW-W64-builds-4.3.5
*/
#ifndef IO_HPP
#define IO_HPP 1

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

void WriteFile(const string& filename,const string& body){
    ofstream ofile(filename);
    ofile<<body;
    ofile.close();
}
string ReadFile(const char * filename){
    ifstream ifile(filename);
    if(!ifile.is_open()){
        cerr<<"文件打开错误";
    }
    ostringstream buf;
    string filestr;
    char ch;
    while(buf && ifile.get(ch)){
        buf.put(ch);
    }
    filestr = buf.str();
    return filestr;
}

#endif