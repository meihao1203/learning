#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class SuffixTreeNode  //后缀树的结点类
{
public:
	SuffixTreeNode() { }
	void insertString(string s,int idx);  //往后缀树中插入一个字符串
	vector<int> getIndex(string s);  //获取字符串在源字符串中出现的位置
	~SuffixTreeNode(); 
private:
	map<char,SuffixTreeNode*> subTreeNode;  //结点出发可以到达的下一个字符以及指向该结点的指针
	vector<int> index;  //存放子字符串在S中的起始位置
	//可能有多个子串，或者从一个结点出发可以找到多个不同子串
};
void SuffixTreeNode::insertString(string s,int idx)
{//建立后缀树
	index.push_back(idx);  //字符串的起始位置保存.放到这里的原因，从root结点开始，等到字后一个字符的时候Str已被耗尽，也就是map没有元素了，但是这个结点index却要保存
	if(s.length()>0)  //如果字符串还没有耗尽，递归接着向下构造后缀树
	{
		char value = s[0];  //结点value的值解释字符串的第一个字符
		//判断该字符在不在该结点的map中，在就继续向下插入下一个字符，不在就新建一个结点并在当前结点的map中保存相关信息
		SuffixTreeNode* next = NULL;
		if(subTreeNode.find(value)!=subTreeNode.end())  //如果结点中存在该字符，next指针指向该结点
		{
			next = subTreeNode.find(value)->second;
		}
		else  //没有该字符，就新建一个结点，并在当前结点的map中保存这个字符值，以及到这个字符的指针
		{
			SuffixTreeNode* node = new SuffixTreeNode;
			subTreeNode.insert(::make_pair(value,node));
			next = node;
		}
		//递归利用字符串中的下一个字符接着构造后缀树
		string subStr = s.substr(1);
		next->insertString(subStr,idx);  //这个子串的起始位置是idx，以后一直是这个，不会变
	}
}
vector<int> SuffixTreeNode::getIndex(string s)
{
	//挨个字符匹配，最后返回最后一个字符所指向的结点的vector
	if(""==s)  //成功匹配到最后返回该结点的index
		return index;
	else
	{
		if(subTreeNode.find(s[0])!=subTreeNode.end())
			return ((subTreeNode.find(s[0]))->second)->getIndex(s.substr(1));  //接着向下匹配
		else 
		{//找不到，直接返回空
			return vector<int>(0);
		}
	}
}
SuffixTreeNode::~SuffixTreeNode()
{//挨个释放动态申请的结点内存
	for(auto it = subTreeNode.begin();it!=subTreeNode.end();++it)
	{
		delete it->second;  //这里是一个递归过程
		it->second = NULL;
	}
}

class SuffixTree
{
public:
	SuffixTree(string str);  //用字符串（源串）初始化一个后缀树
	vector<int> getIndex(string str);  //获取一个字符串在源串中出现的位置
	~SuffixTree();
private:
	SuffixTreeNode* _root;
};

SuffixTree::SuffixTree(string str)
{
	_root = new SuffixTreeNode();
	for(int idx=0;idx!=str.length();++idx)
	{
		string subStr = str.substr(idx);
		_root->insertString(subStr,idx);
	}
}
vector<int> SuffixTree::getIndex(string str)
{
	return _root->getIndex(str);
}
SuffixTree::~SuffixTree()
{
	delete _root;
	_root = NULL;
}
int main(int argc,char** argv)
{
	string testString = "mississippi";
	string arr[4] = {"is","sip","hi","sis"};
	SuffixTree tree(testString);
	for(int idx=0;idx!=4;++idx)
	{
		vector<int> ans = tree.getIndex(arr[idx]);
		cout<<arr[idx]<<" ";
		if(0!=ans.size())
		{
			for(int iidx=0;iidx!=ans.size();++iidx)
			{
				cout<<ans[iidx]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"not find!"<<endl;
		}
	}
	//system("pause");
}
//is 1 4
//sip 6
//hi not find!
//sis 3
//请按任意键继续. . .
