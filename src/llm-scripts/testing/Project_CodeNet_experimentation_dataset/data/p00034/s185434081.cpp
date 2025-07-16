#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>
using namespace std;

vector<string> split(const string &str, char delim){
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}

int main()
{
	string s;
	while(cin >> s)
	{
		vector<string> _s = split(s,',');
		int *values = new int[11];
		double *v = new double[2];

		for(int i=0;i<11;i++)
		{
			if(i == 0)
			{
				values[i] = 0;
			}
			else
			{
				values[i] = std::atoi(_s[i-1].c_str()) + values[i-1];
			}
			
		}

		for(int i=0;i<2;i++)
		{
			v[i] = std::atoi(_s[i+10].c_str());
		}
		double temp = v[0] / (v[0]+v[1]);
		temp *= values[10];

		bool flag = true;
		for(int i=0;i<10;i++)
		{
			if(values[i] <= temp && temp <= values[i+1] && flag)
			{
				cout << i+1 << endl;
				flag = false;
			}
		}
	}
	return 0;
}