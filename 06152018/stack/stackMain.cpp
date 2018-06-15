#include"stack.h"
int test0(void)
{      
        Stack<int, 10> stackInt;
        cout << "开始时stakcInt是否为空?" << stackInt.empty() << endl;
        stackInt.push(5);

        cout << "此始时stakcInt是否为空?" << stackInt.empty() << endl;

        for(int idx = 1; idx !=10; ++idx)
        {
                stackInt.push(idx);
        }
        cout << "此时stakcInt是否已满?" << stackInt.full() << endl;

        for(int idx = 0; idx != 10; ++idx)
        {
                int elem = 0;
                stackInt.pop(elem);
                cout << elem << " ";
        }
        cout << endl;
        return 0;
}
int test1(void)
{      
        Stack<string, 10> stackInt;
        cout << "开始时stakcInt是否为空?" << stackInt.empty() << endl;
        stackInt.push("aa");
        cout << "此始时stakcInt是否为空?" << stackInt.empty() << endl;

        for(int idx = 1; idx !=10; ++idx)
        {
                string s(2, 'a' + idx);  
//string类的一个构造函数，表示含有2个元素的string对象，其中每个元素都初始化为后面的字符
                stackInt.push(s);
        }
        cout << "此时stakcInt是否已满?" << stackInt.full() << endl;

        for(int idx = 0; idx != 10; ++idx)
        {
                string elem;
                stackInt.pop(elem);
                cout << elem << " ";
        }
        cout << endl;
        return 0;
}
int main()
{
        test0();
        test1();
        return 0;
}
