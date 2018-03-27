 ///
 /// @file    mem_fun_ref.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 15:43:02
 ///
 
//成员函数适配器
//mem_fun_ref()   // 函数参数为类对象
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;
class Num
{
	public:
		Num(){  val = 0;  }
		Num(int _val){  val = _val;  }
		bool display(){  cout<<val<<"  "; return true;  }
		bool isEven(){  return (bool)(val%2);  }
		bool isPrime()
		{
			for(int i=2;i<(val/2);++i)
				if(!(val%i)) return false;
			return true;
		}
		friend ostream& operator<<(ostream& os,const Num& rhs);
	private:
		int val;
};
ostream& operator<<(ostream& os,const Num& rhs)
{
	os<<rhs.val;
}
int main()
{
	vector<Num> v1(12);  // 开辟12个空间
	//容器参数为类对象，Num
	for(int i=0;i<12;++i)
	{
		v1[i] = Num(i+1);
	}
	vector<Num>::iterator it;
	cout<<"原始数据："<<endl;
	// for_each(v1.begin(),v1.end(),mem_fun_ref(&Num::display));
	for_each(v1.begin(),v1.end(),mem_fun_ref<bool,Num>(&Num::display));  // 这样写也可以
	cout<<endl;
	cout<<"删除质数："<<endl;
	it = remove_if(v1.begin(),v1.end(),mem_fun_ref(&Num::isPrime));
	for(auto& elem:v1)
		cout<<elem<<"  ";
	cout<<endl;
	v1.erase(it,v1.end());
	for(auto& elem:v1)
		cout<<elem<<"  ";
	cout<<endl;
	vector<Num> v2(12);
	for(int i=0;i<12;++i)
	{
		v2[i] = Num(i+1);
	}
	v2.erase(remove_if(v2.begin(),v2.end(),mem_fun_ref(&Num::isEven)),v2.end());
	cout<<"删除基数："<<endl;
	for(auto& elem:v2)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//原始数据：
//1  2  3  4  5  6  7  8  9  10  11  12  
//删除质数：
//6  8  9  10  12  6  7  8  9  10  11  12  
//6  8  9  10  12  
//删除基数：
//2  4  6  8  10  12  
