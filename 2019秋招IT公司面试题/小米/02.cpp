#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
int findMaxCapacity(vector < int > array, int m) 
{



}
/******************************����д����******************************/


int main() {
	int res;

	int _array_size = 0;
	cin >> _array_size;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	vector<int> _array;
	int _array_item;
	for(int _array_i=0; _array_i<_array_size; _array_i++) {
		cin >> _array_item;
		cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		_array.push_back(_array_item);
	}


	int _m;
	cin >> _m;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



	res = findMaxCapacity(_array, _m);
	cout << res << endl;

	return 0;

}
