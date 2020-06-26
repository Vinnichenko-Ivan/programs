#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include <ctime>

using namespace std;

int searchElement(vector<pair<string,int>> data,string element)
{

	for(int i=0;i<data.size();i++)
	{
		if(data[i].first==element)
		{
			return i;
		}
	}
	return -1;
}

vector<string> inputData()
{
	vector<string>inData;
	ifstream fin("input.txt");
	string buff;
	while(fin >> buff)
	{	
		inData.push_back(buff);
	}
	fin.close();
	return inData;
}

void outputData(vector<pair<string,int>>data)
{	
	ofstream fout;
	fout.open("output.txt");
	for(int i=0;i<data.size();i++)
	{
		fout<<data[i].second<<"\t"<<data[i].first<<"\n";
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


// vector<string> clearingData(vector<string>inData)
// {
// 	vector<string>inData;
// 	for(int i=0;i<inData.size();i++)
// 	{
// 		cout<<data[i];
// 	}
// }

vector<pair<string,int>>sortData(vector<pair<string,int>> data)
{
	vector<pair<string,int>> dataSort;
	vector<pair<string,int>> dataSort1Part;
	vector<pair<string,int>> dataSort2Part;
	int a;
	if((data.size()==1))
	{
		
		return data;
	}
		
	for(int i=0;i<data.size();i++)
	{
		if(i<data.size()/2)
		{
			dataSort1Part.push_back(data[i]);
		}
		else
		{
			dataSort2Part.push_back(data[i]);
		}
	}
	dataSort1Part=sortData(dataSort1Part);
	dataSort2Part=sortData(dataSort2Part);
	for(int i=0,v1=0,v2=0;i<data.size();i++)
	{	
		if(v1<dataSort1Part.size()&&v2<dataSort2Part.size())
		{
			if(dataSort1Part[v1].second<dataSort2Part[v2].second)
			{
				dataSort.push_back(dataSort1Part[v1]);
				v1++;
			}
			else if(dataSort1Part[v1].second>dataSort2Part[v2].second)
			{
				dataSort.push_back(dataSort2Part[v2]);
				v2++;
			}		
			else
			{
				if(dataSort1Part[v1].first<dataSort2Part[v2].first)
				{
					dataSort.push_back(dataSort2Part[v2]);
					v2++;
				}
				else if(dataSort1Part[v1].first>dataSort2Part[v2].first)
				{
					dataSort.push_back(dataSort1Part[v1]);
					v1++;
				}		
				else
				{
					dataSort.push_back(dataSort1Part[v1]);
					v1++;
				}	
			}	
		}
		else
		{
			if(v1<dataSort1Part.size())
			{
				dataSort.push_back(dataSort1Part[v1]);
				v1++;
			}
			else if(v2<dataSort2Part.size())
			{
				dataSort.push_back(dataSort2Part[v2]);
				v2++;
			}
			else
			{
				cout<<"lol aga owibochka";
				break;
			}
		}
	}	
	return dataSort;
}


vector<pair<string,int>>analizeData(vector<string>strData)
{

	vector<pair<string,int>>data;
	int counter;
	for(int i=0;i<strData.size();i++)
	{

		counter=searchElement(data,strData[i]);
		if(counter==-1)
		{
			data.push_back(pair<string,int>(strData[i],1));
		}
		else
		{
			data[counter]=pair<string,int>(strData[i],data[counter].second+1);	
		}
	}
	return data;
}

int main()
{	
	long double start= clock(); 
	vector<string> inData;
	vector<pair<string,int>> data;
	vector<pair<string,int>> data2;
	inData=inputData();
	data=analizeData(inData);
	data=sortData(data);
	data.assign( data.rbegin(), data.rend() );
	outputData(data);
	//cout<<data.size();
	long double end = clock(); // засекаем время окончания
    long double t = (end - start) / CLOCKS_PER_SEC;
    cout<<t;
	outputTime(t);
	return 0;
}