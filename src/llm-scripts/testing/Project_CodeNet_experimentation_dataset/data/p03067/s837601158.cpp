// Created by new_sm
//
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
s.find_by_order(x) xth element in set
x.order_of_key(x) number of elements <x*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define chotu 1000000007
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower())
#define upper_string(s) transform(all(s),s.begin(),::toupper())
#define size(s) s.size()
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
void solve()
{
fastio
int a,b,c;
cin>>a>>b>>c;
if((a<c&&c<b)||(b<c&&c<a))
cout<<"Yes";
else
cout<<"No";
}
int main()
{
//code
fastio
int t;
t=1;
while(t--)
{
	solve();
	cout<<endl;
}
}

