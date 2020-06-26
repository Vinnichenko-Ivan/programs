
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

};

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

	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}