#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

void inputData(map<string,int> &data)
{
	ifstream fin("input.txt");
	string buff;
	while(fin >> buff)
	{	
		if(data[buff]==0)
		{
			data[buff]=1;
		}
		else
		{
			data[buff]=data[buff]+1;
		}
	}
	fin.close();
	return;
}

void outputData(map<int, vector<string>> &sortedData)
{	
	ofstream fout;
	fout.open("output.txt");
	map<int, vector<string>> :: iterator it = sortedData.begin();
    for (int i = 0; it != sortedData.end(); it++, i++) {  // выводим их
    	for(int j=0;j<it->second.size();j++)
    	{

    		fout << it->second[j] << '\t' << it->first<< '\n';
    	}
    }
	fout.close();
}

void outputTime(long double time)
{	
	ofstream fout;
	fout.open("outputTime.txt");
	fout<<time;
	fout.close();
}

void sortingData(map<string,int> &data,map<int, vector<string>> &sortedData)
{
	map <string, int> :: iterator it = data.begin();
    for (int i = 0; it != data.end(); it++, i++) {  // выводим их
        //fout << it->first << '\t' << it->second << '\n';
        sortedData[it->second].push_back(it->first);
    }	
}

int main()
{	
	long double start= clock(); 
	map<string,int> data;
	map<int, vector<string>> sortedData;
	inputData(data);
	sortingData(data,sortedData);
	outputData(sortedData);
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}