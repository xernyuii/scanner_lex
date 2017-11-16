//scanner using c++
#include<cstdio>
#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(){
    string str;
    int int_num=0;
    int float_num=0;
    int id_num=0;
    int error_num=0;
    while(cin>>str){
        if(regex_match(str,regex("[-]*[0-9]+;"))){
            cout<<"Integer"<<" ("<<str<<")"<<endl;
            int_num++;
        }
        else if(regex_match(str,regex("[-]*[0-9]*.[0-9]+;"))){
            cout<<"Float"<<" ("<<str<<")"<<endl;
            float_num++;
        }
        else if(regex_match(str,regex("[a-zA-Z][a-zA-Z0-9_]*;"))){
            cout<<"Id"<<" ("<<str<<")"<<endl;
            id_num++;
        }
        else if(regex_match(str,regex("[0-9a-zA-Z_!@#$%.^*()_+=-{};]+"))){
            cout<<"Error"<<" ("<<str<<")"<<endl;
            error_num++;
        }
    }
    cout<<"int "<<int_num<<"   "<<"float "<<float_num<<"   "<<"Id "<<id_num<<endl;
    
    return 0;
}
