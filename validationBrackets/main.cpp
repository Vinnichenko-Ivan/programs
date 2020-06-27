
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
		map<char,int>countBrakets;
		vector<pair<char,char>>brakets;
		bool searchBraket(char symbol,auto &countBrakets);
		bool coorect(auto &countBrakets,auto &brakets);
	public:
		ValidationBrackets(auto &brakets);
		void addBrakets(auto &brakets);
		bool assert(const string &text);
};

void outputTime(long double time)
{	
	ofstream fout;
	fout.open("outputTime.txt");
	fout<<time;
	fout.close();
}

vector<pair<char,char>>getBrakets(int number, int &answer)
{
	vector<pair<char,char>>data;
	string name="";

	name="tests/keys/test"+to_string(number)+".txt";
	cout<<name<<endl;
	ifstream fin(name);
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
	return data;
}

int main()
{	

	long double start= clock(); 
	for(int i=1, answer;i<6;i++)
	{
		auto braketr=getBrakets(i,answer);
		cout<<answer<<endl;
	}
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}