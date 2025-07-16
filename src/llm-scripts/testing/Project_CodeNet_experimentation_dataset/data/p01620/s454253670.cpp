#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include<algorithm>
#include<complex>
#include<cstdlib>
#include<cctype>

#define REP(i,n) for(int i = 0;i < (n);i++)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cout << v[i] << ' ';cout << endl << endl;}
#define SHOW2d(v,i,j) {for(int a = 0;a < i;a++){for(int b = 0;b < j;b++)cout << v[a][b] << ' ';cout << endl;}cout << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

char f(char c,int n)
{
//	cout << c << ' ';
	REP(i,n)
	{
		if(c == 'a')
			c = 'Z';
		else if(c == 'A')
			c = 'z';
		else
			c--;
	}
//	cout << c << endl;
	return c;
}

int main()
{
	int n;
	
	while(cin >> n,n)
	{
		iv v;
		REP(i,n)
		{
			int tmp;
			cin >> tmp;
			v.PB(tmp);
		}
		
		string str;
		cin >> str;
		
		REP(i,str.size())
		{
			str[i] = f(str[i],v[i%n]);
		}
		
		cout << str << endl;
	}
	
	return 0;
}