/*
Coding:UTF-8
@Author:Limou233[github.com/limou233]
Compiler:MinGW-W64-builds-4.3.5
*/
#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP 1

#include<windows.h>
#include<string>
#include"Colors.hpp"
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

char GetCapsLetter(){//() -> char:CapsLetter | ' '
    for(short i='A';i<'Z';i++){
        if((KEY_DOWN(VK_CAPITAL)||KEY_DOWN(VK_SHIFT))&&KEY_DOWN(i))
          return i;
    }
    return ' ';
}
char GetSmallLetter(){//() -> char:SmallLetter | ' '
    for(short i='A';i<'Z';i++){
        if((!KEY_DOWN(VK_CAPITAL)||!KEY_DOWN(VK_SHIFT))&&KEY_DOWN(i))return i+('a'-'A'); 
    }
    return ' ';
}
char GetLetter(){//() -> char:Caps/Small Letter | ' '
    for(short i='A';i<'Z';i++){
        if((!KEY_DOWN(VK_CAPITAL)||!KEY_DOWN(VK_SHIFT))&&KEY_DOWN(i))
          return i+('a'-'A');
        else if((KEY_DOWN(VK_CAPITAL)||KEY_DOWN(VK_SHIFT))&&KEY_DOWN(i))
          return i;
    }
    return ' ';
}

//设置光标位置
void go(int __x,int __y){//(int:tp_x,int:tp_y) -> void
    COORD coord;
    coord.X=__x*2;
    coord.Y=__y+1;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(a,coord);
}

string InputBox(){//()  -> string:word
    short Max=32;
    go(2,2),ColPrint("                                ",B_LIGHT);//32
    char letter;
    string word;
    Sleep(1000);
    // cout<<"S"<<endl;
    go(2,2);
    while(!KEY_DOWN(VK_RETURN)){//按下VK_RETURN(回车)后结束
        letter=GetLetter();
        if(letter!=' '){
            word+=letter;
        }
        if(KEY_DOWN(VK_BACK)&&word.length()>0){
            word.erase(word.end()-1);
        }
        go(2,2),ColPrint(word,B_LIGHT);
        for(short i=0;i<Max-word.length();i++){
            cout<<" ";
        }
        Sleep(70);
    }
    return word;
}

void clear(){system("cls");system("color 0f");}//() -> void

#endif /*KEYBOARD.HPP*/