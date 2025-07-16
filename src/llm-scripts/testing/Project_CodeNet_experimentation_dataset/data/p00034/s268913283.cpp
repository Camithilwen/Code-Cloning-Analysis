#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace  std;
vector<string> split(const string &s, char delimiter)
{
	vector<string> ret;
	size_t now = 0, find;
	while ((find = s.find_first_of(delimiter, now)) != string::npos)
	{
		ret.push_back(string(s, now, find - now));
		now = find + 1;
	}
	ret.push_back(string(s, now, s.size() - now));
	return ret;
}
int main()
{
	string in;
	while (cin >> in)
	{
		vector<string> v = split(in, ',');
		int disSum = 0;
		int dis[10];
		int sp[2];
		for (int i = 0; i < v.size(); i++)
		{
			stringstream ss;
			ss << v[i];
			if (i < 10)
			{
				ss >> dis[i];
				disSum += dis[i];
			}
			else
			{
				ss >> sp[i - 10];
			}
		}
		double a = disSum * sp[0] / (sp[0] + sp[1]);
		double b = disSum * sp[1] / (sp[0] + sp[1]);

		double fromStart = 0.0;
		double fromEnd = 0.0;
		int i = 0, j = 0;
		for (i = 0; i < 10; i++)
		{
			if (fromStart >= a)
			{
				break;
			}
			fromStart += dis[i];
		}
		for (j = 9; j >= 0; j--)
		{
			if (fromEnd >= b)
			{
				break;
			}
			fromEnd += dis[j];
		}
		/*cout << i << " " << j << endl;
		cout << a << " " << b << " " << fromStart << " " << fromEnd << endl;*/
		if (fromStart == a && fromEnd == b)
		{
			cout << i << endl;
		}
		else
		{
			if (fromStart == fromEnd)i++;
			cout << i << endl;
		}




	}
	return 0;
}