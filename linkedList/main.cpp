
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

struct Node
{
	Node * nextNode;
	int data;
	Node(const int inData);
};

Node::Node(const int inData)
{
	data=inData;
	nextNode=nullptr;
}

int getNNodeData(Node * buffNode,size_t i)
{
	for(;i!=0;i--)
		buffNode=buffNode->nextNode;
	return buffNode->data;
}

int getNNodeReversData(Node * buffNode,size_t i)
{
	Node * first=buffNode;
	for(;i!=0;i--)
		buffNode=buffNode->nextNode;
	while(buffNode->nextNode!=nullptr)
	{
		first = first->nextNode;
		buffNode=buffNode->nextNode;
	}
	return first->data;
}

void push_back(Node * buffNode,const int inData)
{
	while(buffNode->nextNode!=nullptr)
	{
		buffNode=buffNode->nextNode;
	}
	buffNode->nextNode= new Node(inData);
}

void outputTime(long double time)
{	
	ofstream fout;
	fout.open("outputTime.txt");
	fout<<time;
	fout.close();
}

int main()
{	
	long double start= clock(); 
	Node * first=new Node(0);
	
	for(int i =1;i<100000;i++)
	{
		push_back(first,i);
	}
	cout<<getNNodeData(first,7)<<endl;
	cout<<getNNodeReversData(first,7)<<endl;
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}