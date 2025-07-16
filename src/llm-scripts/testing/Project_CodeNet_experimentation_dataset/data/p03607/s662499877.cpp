//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//Tariquzzaman Faisal
//_Faisal101_
//IUT_CSE'19
//190041101
 
#include<iostream>
#include<stdio.h>
#include<vector>
#include<deque>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iterator>
#include<set>
#define fileOut freopen("out.txt","w",stdout)
#define fileIn freopen("in.txt","r",stdout)
#define testcases ll TC,T; cin >> TC; for(T=1; T<=TC; T++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INFLL 9223372036854775807
#define INF 2147483647
#define pi acos(-1.0)
#define ll long long
#define endll printf("\n")
#define CASE printf("Case %lld: ",T)
#define ff first
#define ss second
#define mem(ara,n) memset(ara,n,sizeof ara)
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mid3(a,b,c) min(max(a,b),max(b,c),max(a,b))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define endl '\n'
#define ld long double
 
 
using namespace std;


int main(){
	ll n;
	cin >> n;
	ll x;
	set <ll> st;
	while(n--){
		cin >> x;
		if(!st.count(x)){
			st.insert(x);
		}
		else{
			st.erase(st.find(x));
		}
	}
	cout<< st.size() <<endl;
	return 0;
}