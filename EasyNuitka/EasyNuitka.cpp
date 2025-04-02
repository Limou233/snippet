/*
@Author: Limou233[github.com/limou233]
GCCversion: 5.1.0
*/
#include"my_libs/Colors.hpp"
#include<stdlib.h>
using namespace std;

struct Opts{
    string name;
    string note;
    string value;
    bool is_easy;//1:常用 0:命令解释
};

Opts fast_opts[]={
    "--exe","打包为单文件exe","nuitka --standalone --onefile --show-progress",true,
    "--env-exe","打为可执行文件(带有执行目录,且该目录是必要的)","nuitka --standalone --show-progress",true,
};
Opts a_opts[]={

};

bool is_inc_nuitka(){
    char* p=getenv("PATH");
    string path=p;
    
}

int main(){
    ColPrint("\n \
  _____                _   _       _ _   _\n \
 | ____|__ _ ___ _   _| \\ | |_   _(_) |_| | ____ _\n \
 |  _| / _  / __| | | |  \\| | | | | | __| |/ / _  |\n \
 | |__| (_| \\__ \\ |_| | |\\  | |_| | | |_|   < (_| | \n \
 |_____\\__,_|___/\\__, |_| \\_|\\__,_|_|\\__|_|\\_\\__,_|\n \
                 |___/\n ",F_BlUE);
    ColPrint("By(limou233)[https://github.com/limou233]",F_GREEN,true);
    cout<<"常用命令:"<<endl;
    for(int i=0;i<sizeof(fast_opts)/sizeof(fast_opts[0]);i++){
        ColPrint(fast_opts[i].name+" ",F_BlUE);
        ColPrint(fast_opts[i].note,F_GREEN);
        cout<<endl;
    }
    cout<<"使用方法 `enuitka` <参数>"<<endl;
}