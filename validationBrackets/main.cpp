
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

class ValidationBrackets
{
	private:
		map<char,char>pairBraketsOpen;
		map<char,char>pairBraketsClose;
		string braketsText="";
		//bool coorect(auto &countBrakets,auto &inBrakets);
	public:
		ValidationBrackets(auto inBrakets);
		//void addBrakets(auto &brakets);
		bool assert( string &text);
};

bool ValidationBrackets::assert( string &text)
{
	vector<char>stack;
	for(int i=0;i<text.size();i++)
	{
		if(pairBraketsOpen[text[i]]!=0)
		{
			stack.push_back(text[i]);
		}
		if(pairBraketsClose[text[i]]!=0)
		{
			if(stack[stack.size()-1]==pairBraketsClose[text[i]]&&stack.size()>0)
			{
				stack.pop_back();
			}
			else
			{
				return 0;
			}
		}		
	}
	if(stack.size()==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	cout<<braketsText<<endl;
}



ValidationBrackets::ValidationBrackets(auto inBrakets)
{
	for(int i =0;i<inBrakets.size();i++)
	{
		pairBraketsOpen[inBrakets[i].first]=inBrakets[i].second;
		pairBraketsClose[inBrakets[i].second]=inBrakets[i].first;
	}
}

void outputTime(long double time)
{	
	ofstream fout;
	fout.open("outputTime.txt");
	fout<<time;
	fout.close();
}

vector<pair<char,char>>getTest(const int number, int &answer,string &text)
{
	vector<pair<char,char>>data;
	string nameTest="";
	nameTest="tests/test"+to_string(number)+".txt";
	string nameKey="";
	nameKey="tests/keys/test"+to_string(number)+".txt";
	ifstream fin(nameKey);
	int counter;
	string buff;
	fin>>counter;
	for(int i=0;i<counter;i++)
	{
		fin>>buff;
		data.push_back(pair<char,char>(buff[0],buff[1]));
	}
	fin>>answer;
	fin.close();
	fin.open(nameTest);
	fin>>text;
	fin.close();
	return data;
}

int main()
{	
	long double start= clock(); 
	for(int i=1, answer;i<6;i++)
	{
		string text;
		ValidationBrackets validationBrackets(getTest(i,answer,text));
		cout<<endl<<"/------------------------------------------/"<<endl;
		cout<<answer<<validationBrackets.assert(text)<<endl;

	}
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}