// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<string>
#include<set> 
#include<vector>

using namespace std;

string fun(int n, string str)
{
	vector<vector<int> > Value(n);

	//set<int> tmp;
	vector<int> count;

	for (int i = 0; i<n; i++)
	{
		vector<int> flag;
		vector<int>::iterator it;
		for (int k = 0; k<n; k++)
			Value[i].push_back(0);

		flag.push_back(i);

		for (int j = 0; j<flag.size(); j++)
		{
			if (str[flag[j]] == 'c')
			{
				if (flag[j] + 1 < n)
				{
					it = find(flag.begin(), flag.end(), flag[j] + 1);
					if (it == flag.end())
						flag.push_back(flag[j] + 1);
				}
					
				if (flag[j] + 2<n)
				{
					it = find(flag.begin(), flag.end(), flag[j] + 2);
					if (it == flag.end())
						flag.push_back(flag[j] + 2);
				}
				if (flag[j] - 1 >= 0)
				{
					it = find(flag.begin(), flag.end(), flag[j] - 1);
					if (it == flag.end())
						flag.push_back(flag[j] - 1);
				}
				if (flag[j] - 2 >= 0)
				{
					it = find(flag.begin(), flag.end(), flag[j] - 2);
					if (it == flag.end())
						flag.push_back(flag[j] - 2);
				}
			}
			Value[i][flag[j]] = 1;
		}

		count.push_back(flag.size());
	}

	int pos = 0;

	for (int i = 1; i<n; i++)
	{
		if (count[pos]<count[i])
			pos = i;
	}

	string res;
	for (int i = 0; i<n; i++)
	{
		if (Value[pos][i] == 1)
			res += 'I';
		else
			res += 'U';
	}

	return res;
}


int main()
{
	int num = 18;
	string str = "ncncncnnncnccncnnn";

	cout << fun(num, str) << endl;

	return 0;

}

