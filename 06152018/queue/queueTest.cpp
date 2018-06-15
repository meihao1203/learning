#include"queue.h"
int main()
{
        queue<int,10> q1;
        q1.push(3);
        q1.push(5);
        int tmp;
        cout<<q1.size()<<endl;
        q1.pop(tmp);
        cout<<tmp<<endl;
        cout<<"----------------------"<<endl;
        queue<string,5> q2;
        q2.push("hello");
        q2.push("world");
        cout<<q2.size()<<endl;
        string tmpString;
        q2.pop(tmpString);
        cout<<q2.size()<<"  "<<tmpString<<endl;
        return 0;
}
//2
//3
//----------------------
//2
//1  hello
