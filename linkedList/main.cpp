
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

struct Node
{
	public:
		Node * nextNode;
		int data;
		Node(const int inData);
		void push_back(const int inData);
		Node* getNode();
		Node* getNextNode();
		int getNNodeData(int i);
};

int Node::getNNodeData(int i)
{
	if(i==0)
	{
		return data;
	}
	else if(nextNode==NULL)
	{
		return NULL;
	}
	else
	{
		nextNode->getNNodeData(i-1);
	}
}

Node* Node::getNextNode()
{
	return nextNode;
}

Node::Node(const int inData)
{
	data=inData;
	nextNode=NULL;
}

void Node::push_back(const int inData)
{
	if(nextNode==NULL)
	{
		nextNode=new Node(inData);
	}
	else
	{
		nextNode->push_back(inData);
	}
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
	
	for(int i =1;i<100;i++)
	{
		first->push_back(i);
	}
	cout<<first->getNNodeData(3)<<endl;
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}