 ///
 /// @file    tryCatch03.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-02 16:45:47
 ///
 
//自己实现异常
#include<iostream>
#include<string>
using namespace std;
class exA
{
	public:
		exA(string strA):_strA(strA){ cout<<"exA()"<<endl; }
		~exA(){ cout<<"~exA()"<<endl; }
		virtual const char* what()const throw()
		{
			return _strA.c_str();
		}
	private:
		string _strA;
};
class exB : public exA
{
	public:
		exB(string strB):_strB(strB),exA("exA"){ cout<<"exB()"<<endl; }
		~exB(){ cout<<"~exB()"<<endl; }
		const char* what()const throw()
		{
			return _strB.c_str();
		}
	private:
		string _strB;
};
void fun(int n) throw(int,exA,exB)  //只能抛出int,exA,exB类型错误
{
	if(1==n){throw 1;}
	else if(2==n){throw exA("this is exA");}
	else if(3==n){ throw exB("this is exB");}
	else {throw 2.2;}
}
int main()
{
	try
	{
	//	fun(1);
	//	fun(2);
		fun(3);  //这里最终调动的是exA
		//因为在抛出异常对象的时候又建立了一个exA对象
		//要想执行异常exB,就要注释掉catch(exA& b)
		//不注释掉最后结果就是程序最后面一个
	//	fun(4);  //运行出现下列错误
		//terminate called after throwing an instance of 'double'
		//Aborted (core dumped)
	}
	catch(int a)
	{
		cout<<"throw int"<<endl;
	}
//	catch(exA& b)
//	{
//		cout<<b.what()<<endl;
//		cout<<"throw exA"<<endl;
//	}
	catch(exB& c)
	{
		cout<<c.what()<<endl;
		cout<<"throw exB"<<endl;
	}
	catch(...)
	{
		cout<<"oth exception"<<endl;
	}
	return 0;
}
//throw int

//exA()
//throw exA
//~exA()

//exA()
//this is exA
//throw exA
//~exA()

//exA()
//exB()
//this is exB
//throw exB
//~exB()
//~exA()

//exA()
//exB()
//this is exB
//throw exA
//~exB()
//~exA()
