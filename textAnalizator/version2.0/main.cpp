
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

map<string,int> inputData()
{
	map<string,int> data;
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
	return data;
}

void outputData(map<int, vector<string>> &sortedData)
{	
	ofstream fout;
	fout.open("output.txt");
	auto it = sortedData.rbegin();
    for (int i = 0; it != sortedData.rend(); it++, i++) {  // выводим их
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

map<int, vector<string>> sortData(map<string,int> &data)
{
	map<int, vector<string>>sortedData;
	map <string, int> :: iterator it = data.begin();
    for (int i = 0; it != data.end(); it++, i++) 
    { 
        //fout << it->first << '\t' << it->second << '\n';
        sortedData[it->second].push_back(it->first);
    }	
    return sortedData;
}

int main()
{	
	long double start= clock(); 
	auto data = inputData();
	auto sortedData = sortData(data);
	outputData(sortedData);
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}