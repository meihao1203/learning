 ///
 /// @file    pureVirtual.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 09:41:08
 ///
 
#include<iostream>
#include<math.h>
#define PI 3.14
using namespace std;
class figure
{
	public:
		virtual void display()=0;
		virtual float area()=0;
};
class circle:public figure
{
	public:
		circle(int redius):_redius(redius){}
		void display()
		{
			cout<<"圆"<<endl;
		}
		float area()
		{
			return PI*pow(_redius,2);
		}
	private:
		float _redius;
};
class rectangle:public figure
{
	public:
		rectangle(int length=0,int width=0):_length(length),_width(width){}
		void display()
		{
			cout<<"矩形"<<endl;
		}
		float area()
		{
			return _length*_width;
		}
	private:
		float _length;
		float _width;
};
class triangle:public figure
{
	public:
		triangle(int a=0,int b=0,int c=0):_a(a),_b(b),_c(c){}
		void display()
		{
			cout<<"三角形"<<endl;
		}
		float area()
		{
			float p = (_a+_b+_c)/2;
			return sqrt(p*(p-_a)*(p-_b)*(p-_c));
		}
	private:
		float _a;
		float _b;
		float _c;
};
void test(figure* fig)
{
	fig->display();
	cout<<"面积是："<<fig->area()<<endl;
}
int main()
{
	circle c1(10);
	rectangle r1(2,3);
	triangle t1(3,4,5);
	test(&c1);
	test(&r1);
	test(&t1);
	return 0;
}
//圆
//面积是：314
//矩形
//面积是：6
//三角形
//面积是：6
