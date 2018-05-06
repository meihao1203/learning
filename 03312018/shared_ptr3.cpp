 ///
 /// @file    shared_ptr3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 19:51:58
 ///
 
#include<iostream>
#include<memory>
using namespace std;
class point:public enable_shared_from_this<point>
{
	public:
		point(int x=0,int y=0):_x(x),_y(y){ cout<<"point(int,int)"<<endl; }
		~point(){ cout<<"~point()"<<endl; }
#if 0
		point* add(const point* rhs)
		{
			_x += rhs->_x;
			_y += rhs->_y;
			return this;
		}
#endif
		shared_ptr<point> add(const point* rhs)
		{
			//在类内部进行托管
			_x += rhs->_x;
			_y += rhs->_y;
			//return shared_ptr<point>(this); // 和point* add(cosnt point*)一个效果。
			return shared_from_this();
			//这个方法在enable_shared_from_this<class T>中
		}
		friend ostream& operator<<(ostream& ,const point&);
	private:
		int _x;
		int _y;
};
ostream& operator<<(ostream& os,const point& rhs)
{
	os<<"("<<rhs._x<<","<<rhs._y<<")";
}
void test1()//对shared_ptr误用
{ //1、对shared_ptr的误用
	point* p1 = new point(1,2);
	shared_ptr<point> sp1(p1);
	cout<<"sp1 use count="<<sp1.use_count()<<endl;
	shared_ptr<point> sp2(sp1);
	//重复对一个对象托管,会导致多次调用析构函数
	cout<<"sp1 use count="<<sp1.use_count()<<endl;
	cout<<"sp2 use count="<<sp2.use_count()<<endl;
}
void test2()
{
	shared_ptr<point> p1(new point(1,2));
	shared_ptr<point> p2(new point(3,4));
	cout<<"p1 use count="<<p1.use_count()<<"  p2 use count="<<p2.use_count()<<endl;
	p2.reset(p1.get());  // reset先释放p2，在把p1的值赋给p2
	cout<<"addr p1="<<p1<<endl;
	cout<<"addr p2="<<p2<<endl;
	cout<<"p1 use count="<<p1.use_count()<<"  p2 use count="<<p2.use_count()<<endl;
}
void test3()
{
	shared_ptr<point> p1(new point(1,2));
	shared_ptr<point> p2(new point(3,4));
	//误用, p1和p3同时托管一个对象
	shared_ptr<point> p3(p1->add(p2.get()));
	cout<<"p1 use count="<<p1.use_count()<<endl;
	cout<<"p2 use count="<<p2.use_count()<<endl;
	cout<<"p3 use count="<<p3.use_count()<<endl;	
	cout<<"p1="<<p1<<"  p2="<<p2<<"  p3="<<p3<<endl;
}
int main()
{
	test1();  // 这里test1()和test2()同时打开段错误，不知道为啥
	cout<<"---------------"<<endl;
	//test2();  // 和上面同样的原因，我猜测是前面开辟的堆内存没有释放，后面又要来delete,所以出现错误。 
	cout<<"---------------"<<endl;
	//test3();
	return 0;
}
//point(int,int)
//sp1 use count=1
//sp1 use count=1
//sp2 use count=1
//~point()
//~point()
//---------------
//point(int,int)
//point(int,int)
//p1 use count=1  p2 use count=1
//~point()
//addr p1=0x244e030
//addr p2=0x244e030
//p1 use count=1  p2 use count=1
//~point()
//~point()
//---------------
//point(int,int)
//point(int,int)
//p1 use count=1
//p2 use count=1
//p3 use count=1
//p1=0xbd5030  p2=0xbd5070  p3=0xbd5030
//~point()
//~point()
//~point()

//采用返回shared_from_this()
//---------------
//point(int,int)
//point(int,int)
//p1 use count=2
//p2 use count=1
//p3 use count=2
//p1=0xc2f030  p2=0xc2f070  p3=0xc2f030
//~point()
//~point()
