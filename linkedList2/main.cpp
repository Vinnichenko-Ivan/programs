
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

struct Node
{
<<<<<<< HEAD
	public:
		Node * nextNode;
		int data;
		Node(int inData);
		void push_back(int inData);//добавить последним
		void insert(int n,int inData);
		Node* getNode();
		Node* getNextNode();
		int getNNodeData(int i);
		int find(int inData);
		void changeData(int i,int dataIn);
		Node * getNNode(int i);
};

Node * Node::getNNode(int i)
{
	if(i==0)
	{
		return this;
	}
	else if(nextNode==NULL)
	{
		return NULL;
	}
	else
	{
	    return nextNode->getNNode(i-1);
	}
}

void Node::changeData(int i,int inData)
{
	if(i==0)
	{
		data=inData;
	}
	else if(nextNode==NULL)
	{
		return;
	}
	else
	{
	    nextNode->changeData(i-1,inData);

	}
}

int Node::find(int inData)
{
	if(inData==data)
	{
		return 0;
	}
	else if(nextNode==NULL)
	{
		return -1;
	}
	else
	{
		int a = nextNode->find(inData);
		if(a==-1)
		{
			return -1;
		}
		return a+1;
	}
}

void Node::insert(int n,int inData)
{
	if(n==0)
	{
		Node * buffNode;
		buffNode = nextNode;
		nextNode = new Node(inData);
		nextNode->nextNode=buffNode;
		return;
	}
	else
	{
		nextNode->insert(n-1,inData);
		return;
	}
}

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
		return nextNode->getNNodeData(i-1);
	}
=======
	Node * nextNode;
	int data;
	Node(const int inData);
};

Node::Node(const int inData)
{
	data=inData;
	nextNode=nullptr;
>>>>>>> aeb62e7940bebfe2a8d6e7124ce0a83f52c32c08
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
<<<<<<< HEAD
	first->push_back(2);
	first->insert(1,3);
	first->push_back(4);
	first->push_back(5);
	cout<<first->getNNodeData(0)<<endl;
	cout<<first->getNNodeData(1)<<endl;
	cout<<first->getNNodeData(2)<<endl;
	cout<<first->getNNodeData(3)<<endl;
	cout<<first->find(2)<<endl;
=======
	
	for(int i =1;i<100000;i++)
	{
		push_back(first,i);
	}
	cout<<getNNodeData(first,7)<<endl;
	cout<<getNNodeReversData(first,7)<<endl;
>>>>>>> aeb62e7940bebfe2a8d6e7124ce0a83f52c32c08
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}