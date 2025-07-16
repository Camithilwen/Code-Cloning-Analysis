#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S , T;
	while(getline(cin , S))for(size_t i = 0; i < 26; i++)
	{
		for(auto &x : S)if('a' <= x&&x <= 'z')if(++x > 'z')x -= 26;
		stringstream SS;
		SS << S;
		vector<string>VS;
		while(SS >> T)if(T == "the" || T == "this" || T == "that" || T == "ths." || T == "this." || T == "that.")
		{
			cout << S << endl;
			break;
		}
	}
}