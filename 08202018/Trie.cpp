#include<iostream>
#include<string.h>
using namespace std;
const int branchNum = 26;  //26个英文字符
class Trie_node
{
public:
	Trie_node():isStr(false){ memset(next,NULL,sizeof(next)); }
public:
	bool isStr;  //记录此处是否构成一个串
	Trie_node* next[branchNum];  //指向各个子树的指针,数组下标就相当于字母的值
};
class Trie
{
public:
	Trie():_root(new Trie_node())	{}
	void insert(const char* word);
	bool search(const char* word)const;
	void deleteTrie(Trie_node* root);
	Trie_node* getTrie()const{ return _root; }
private:
	Trie_node* _root;
};
void Trie::insert(const char* word)
{
	Trie_node* cur = getTrie();
	while(*word)
	{
		if(cur->next[*word - 'a']==NULL)
		{
			Trie_node* node = new Trie_node();
			cur->next[*word - 'a'] = node;
		}
		cur = cur->next[*word - 'a'];  //指向下一个
		++word;
	}
	//插入完毕，字符串最后一个结点标记为true，表示到此已经是一个单词了
	cur->isStr = true;
}
bool Trie::search(const char* word)const
{
	Trie_node* cur = getTrie();
	while(*word&&NULL!=cur)  //单词还没匹配完，下一个字符存在，就接着向下匹配
	{
		cur = cur->next[*word - 'a'];
		++word;
	}
	//判断是不是找到了这个字符串
	return (cur!=NULL && cur->isStr);  //注意这里的判断顺序，如果第一个满足，接着判断第二个；如果第一个不满足就直接返回；是一个开关语句
	// 如果cur==NULL,先判断cur->isStr就要段错误
}
void Trie::deleteTrie(Trie_node* root)
{
	if(NULL!=root)
	{
		for(int idx=0;idx!=branchNum;++idx)
		{
			deleteTrie(root->next[idx]);
			delete root;
			root = NULL;
		}
	}
}
int main()
{
	Trie myTrie;
	const char* arr[] = {"mei","hao","hello","world"};
	for(int idx=0;idx!=4;++idx)
	{
		myTrie.insert(arr[idx]);
	}
	cout<<endl;
	for(int idx=0;idx!=4;++idx)
	{
		cout<<myTrie.search(arr[idx])<<" ";
	}
	cout<<endl;
	cout<<myTrie.search("meihao")<<endl;
}
//
//1 1 1 1
//0
//请按任意键继续. . .
