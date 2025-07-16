#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	reverse(all(a));
	reverse(all(b));
	reverse(all(c));

	char now = 'a';
	while (true)
	{
		if (now == 'a')
		{
			if(a.size() == 0){
				cout << "A" << endl;
				return 0;
			}
			now = a.back();
			a.pop_back();
		}
		if(now == 'b'){
			if(b.size() == 0){
				cout << "B" << endl;
				return 0;
			}
			now = b.back();
			b.pop_back();
		}
		if(now == 'c'){
			if(c.size() == 0){
				cout << "C" << endl;
				return 0;
			}
			now = c.back();
			c.pop_back();
		}
	}

	return 0;
}