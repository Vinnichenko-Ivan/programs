
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

void saveRect(vector<vector<int>> &rect,ofstream &fout)
{
	int size = rect.size();
	int lenCell=0;
	int buffer=size*size;
	while (buffer!=0)
	{
		lenCell++;
		buffer/=10;
	}

	for(int x = 0; x<size; x++)
	{
		for(int y = 0; y<size; y++)
		{
			fout<<rect[x][y];
			int buff = rect[x][y];
			int len=0;

			while (buff!=0)
			{
				len++;
				buff/=10;
			}
			len=lenCell-len;
			while (len>0)
			{
				len--;
				fout<<" ";
			}
			fout<<" ";
		}
		fout<<endl;
	}
	fout<<endl;		
}

bool testingRect(vector<vector<int>> &testRect)
{
	int size = testRect.size();
	int sum = 0;
	vector<bool> usingNumber(size+1,false);
	for(int x = 0; x<size; x++)
	{
		for(int y = 0; y<size; y++)
		{
			if(!usingNumber[testRect[x][y]])
			{
				usingNumber[testRect[x][y]] = true;
			}
			else
			{
				return 0;
			}
		}
	}	

	for(int x = 0; x < size; x++)
	{
		sum+=testRect[x][0];
	}

	for(int x = 0; x < size; x++)
	{
		int buffSum = 0;

		for(int y = 0; y < size; y++)
		{
			buffSum += testRect[x][y];
		}

		if(buffSum != sum)
		{
			return 0;
		}
	}

	for(int y = 0; y<  size; y++)
	{
		int buffSum = 0;
		
		for(int x = 0; x < size; x++)
		{
			buffSum += testRect[x][y];
		}

		if(buffSum!=sum)
		{
			return 0;
		}
	}
	int buffSum = 0;
	
	for(int x = 0, y = 0; x < size; x++,y++)
	{
		buffSum += testRect[x][y];
	}

	if(buffSum!=sum)
	{
		return 0;
	}

	buffSum = 0;
	
	for(int x = 0, y = size-1; x<  size; x++,y--)
	{
		buffSum += testRect[x][y];
	}
	
	if(buffSum != sum)
	{
		return 0;
	}

	return 1;
}

void magicRectGenerator(int n, int x, int y, vector<vector<int>> &rect,ofstream &fout)
{
	//cout<<x<<" "<<y<<endl;
	if( x == n - 1 && y == n - 1)
	{
		for(int i = 1; i <= n * n;i++)
		{
			rect[x][y]=i;
			if(testingRect(rect))
			{
				saveRect(rect, fout);
			}
		}
		return;
	}

	else if(x==n-1)
	{
		for(int i = 1;i <= n * n;i++)
		{
			rect[x][y] =i ;
			magicRectGenerator(n, 0, y+1, rect, fout);
		}
		return;
	}

	for(int i = 1; i <= n * n;i++)
	{
		rect[x][y]=i;
		magicRectGenerator(n, x+1, y, rect, fout);
	}
	return;
}

void testSystem(ofstream &fout)
{
	for(int i = 1;1;i++)
	{
		cout<<endl<<endl<<"start testing n = "<<i<<endl<<endl;
		vector<vector<int>> testRect (i,vector<int>(i));
		fout<<endl<<endl<<"start testing n = "<<i<<endl<<endl;
		long double start= clock(); 
		magicRectGenerator(i,0,0,testRect,fout);
		long double end = clock(); // засекаем время окончания
    	long double t = (end - start) / CLOCKS_PER_SEC;
    	fout<<"testing end"<< endl << "time = "<<t<<endl<<endl;
    	cout<<"testing end"<< endl << "time = "<<t<<endl<<endl;
	}
}

int main()
{	
	ofstream fout("output.txt");
	testSystem(fout);
	return 0;
}