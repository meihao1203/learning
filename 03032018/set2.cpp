 ///
 /// @file    set2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 20:44:14
 ///
 
#include<iostream>
#include<set>
using namespace std;
class point
{
	public:
		point(int ix=0,int iy=0):_ix(ix),_iy(iy){}
		int multiply()const
		{
			return _ix*_iy;
		}
	private:
		int _ix;
		int _iy;
		friend ostream& operator<<(ostream&,const point&);
		friend bool operator>(const point&,const point&);
		friend bool operator<(const point&,const point&);
};
ostream& operator<<(ostream& os,const point &rhs)
{
	os<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return os;
}
bool operator>(const point& lhs,const point& rhs)
{
	return lhs.multiply()>rhs.multiply();
}
bool operator<(const point& lhs,const point& rhs)
{
	return lhs.multiply()<rhs.multiply();
}
int main()
{
	point arr[]={point(3,4),point(1,3),point(-1,8),point(2,8),point(-1,2)};
	set<point,greater<point> > se(arr,arr+sizeof(arr)/sizeof(point));
	for(auto& elem:se)
		cout<<elem<<"  ";
	cout<<endl;
	set<point> se2(arr,arr+sizeof(arr)/sizeof(point));
	for(auto& elem:se2)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//(2,8)  (3,4)  (1,3)  (-1,2)  (-1,8)  
//(-1,8)  (-1,2)  (1,3)  (3,4)  (2,8)  
