 ///
 /// @file    String.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-01 15:38:00
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class String
{ //23种设计模式之代理模式
        class charProxy;
        public:
                String():_pstr(new char[2])
                {
                        cout<<"String()"<<endl;
                        initRefcount();
                }
                String(const char *);
                String(const String&);
                String& operator=(const String&);
                ~String()
                {
                        cout<<"~String()"<<endl;
                        decreaseRefcount();
                        if(0==useCount())
                        {
                                delete []_pstr;
                        }
                }
                int useCount()
                {
                        return _pstr[strlen(_pstr)+1];
                }
                charProxy operator[](int index); //区分写操作，这里要返回一个临时对象就不能是一个引用了
                // char& operator[](int idx)const;  //区分读操作，必须加const关键字，不然和前面函数构成重载
        private:
                char* _pstr;
                void initRefcount()
                {
                        _pstr[strlen(_pstr)+1] = 1;
                }
                void increaseRefcount()
                {
                        ++_pstr[strlen(_pstr)+1];
                }
                void decreaseRefcount()
                {
                        --_pstr[strlen(_pstr)+1];
                }
                class charProxy
                {
                        public:  //这些函数一定要是共有
                                charProxy(String& str,int index):_str(str),_index(index)
                                {
                                        cout<<"charProxy(String&,int)"<<endl;
                                }
                                char& operator=(char ch);         //嵌套类里面，也不能返回对象引用;因为嵌套类对象都是临时的
                                operator char()
                                { //类型转换函数，由Charproxy转向char
                                        cout<<"operator char()"<<endl;
                                        return _str._pstr[_index];
                                }
                        private:
                                String& _str;
                                int _index;
                };
                friend ostream& operator<<(ostream&,const String&);
                friend istream& operator>>(istream&,String&);
};
#if 0
//operator[]()不能区分读操作还是写操作
char & String::operator[](int idx)const       //不能区分读写操作，废弃
{
        cout<<"operator [](int)const"<<endl;
        return _pstr[idx];
}
#endif
String::String(const char* tmp)
{
        cout<<"String(const char*)"<<endl;
        _pstr = new char[strlen(tmp)+2];
        strcpy(_pstr,tmp);
        initRefcount();  //引用计数设置为1
}
String::String(const String& lhs)
{
        cout<<"String(const String&)"<<endl;
        _pstr = lhs._pstr;
        increaseRefcount();
}
String& String::operator=(const String& lhs)
{
        cout<<"String& operator=(const String&)"<<endl;
        decreaseRefcount();
        if(0==useCount())
        {
                delete []_pstr;
        }
        _pstr = lhs._pstr; // 浅拷贝
        increaseRefcount();
        return *this; 
}
ostream& operator<<(ostream& os,const String& rhs)
{
        cout<<"ostream& operator<<(ostream& os,const String&)"<<endl;
        os<<rhs._pstr<<endl;
        return os;
}
istream& operator>>(istream& is,String& s)
{
        cout<<"istream& operator>>(istream&,String&)"<<endl;
        is>>s._pstr;
        return is;
}
String::charProxy String::operator[](int index)
{
        cout<<"charProxy operator[](int)"<<endl;
        return charProxy(*this,index);     //返回临时嵌套类对象
}
char& String::charProxy::operator=(char ch)
{
        cout<<"char& operator=(char)"<<endl;
        if(_index>=0&&_index<strlen(_str._pstr))
        {
                if(1==_str.useCount())  //当对象没有共享内存时
                {
                        _str._pstr[_index] = ch;  //修改
                        return _str._pstr[_index];
                }
                else
                {
                        _str.decreaseRefcount();  //有共享内存
                        char* _strtmp = new char[strlen(_str._pstr)+2];
                        strcpy(_strtmp,_str._pstr);
                        _str = _strtmp;  //这里调用了构造函数和拷贝构造函数,操作完之后调用析构函数
                        _str[_index] = ch;  //这里再次调动[]重载函数,进行修改
                        _str.initRefcount();
                        return _str._pstr[_index];
                }
        }
}
int main()
{
        String s1("hello,world");
        String s2(s1);
        cout<<"读操作："<<s1[1]<<endl;
        cout<<s1.useCount()<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"写操作："<<endl;
        s1[1] = 'm';
        cout<<"--------------------------"<<endl;
        cout<<s1[1]<<endl;
        cout<<s1.useCount()<<endl;
        return 0;
}
//String(const char*)
//String(const String&)
//charProxy operator[](int)
//charProxy(String&,int)
//operator char()
//读操作：e
//2
//--------------------------
//写操作：
//charProxy operator[](int)
//charProxy(String&,int)
//char& operator=(char)
//String(const char*)
//String& operator=(const String&)
//~String()
//charProxy operator[](int)
//charProxy(String&,int)
//char& operator=(char)
//--------------------------
//charProxy operator[](int)
//charProxy(String&,int)
//operator char()
//m
//1
//~String()
//~String()
