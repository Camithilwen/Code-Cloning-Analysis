#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	map<int,int> even,odd; //mapで各数列での要素の出現数を記録する
	for(int i = 0; i < n; i++){
		if(i%2==0) odd[v[i]]++;
		else even[v[i]]++;
	}

	int even_1=0,even_2=0,odd_1=0,odd_2=0;
	int e1=0,e2=0,o1=0,o2=0;
	int cnt = 0;
	for(auto itr = even.begin();  itr != even.end() ; ++itr){
		if(itr->second > cnt){
			cnt = itr->second;
			even_1 = itr->first;
		}
	}
	e1 = cnt;
	cnt = 0;
	for(auto itr = even.begin();  itr != even.end() ; ++itr){
		if(itr->second > cnt && itr->first != even_1){
			cnt = itr->second;
			even_2 = itr->first;
		}
	}
	e2 = cnt;

	cnt = 0;
	for(auto itr = odd.begin();  itr != odd.end() ; ++itr){
		if(itr->second > cnt){
			cnt = itr->second;
			odd_1 = itr->first;
		}
	}
	o1= cnt;
	cnt = 0;
	for(auto itr = odd.begin();  itr != odd.end() ; ++itr){
		if(itr->second > cnt && itr->first != odd_1){
			cnt = itr->second;
			odd_2 = itr->first;
		}
	}
	o2=cnt;

	if(even_1 == odd_1){
		cout << min(n-e1-o2, n-e2-o1) << endl;
	}else{
		cout << n-e1-o1 << endl;
	}

	return 0;
}