#include <cassert>

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#include <boost/foreach.hpp>
//#include <boost/range/algorithm.hpp>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define Sort(v) sort(all(v))
#define INF 1e9
#define LINF 1e18
#define END return 0
#define pb push_back
#define se second
#define fi first
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define MP make_pair
#define MOD 1000000007LL
#define int long long
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct edge{int to,cost;};
typedef pair<int,int> P;

bool isupper(char c){if('A'<=c&&c<='Z')return 1;return 0;}
bool islower(char c){if('a'<=c&&c<='z')return 1;return 0;}
bool isPrime(int x){if(x==1)return 0;if(x==2)return 1;if(x%2==0)return 0;for(int i=3;i*i<=x;i++)if(x%i==0)return 0;return 1;}
bool iskaibun(string s){for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])return 0;return 1;}
bool isnumber(char c){return ('0'<=c&&c<='9');}
bool isalpha(char c){return (isupper(c)&&islower(c));}
void printvi(vector<int> v){rep(i,0,v.size()){if(i)cout<<" ";cout<<v[i];}cout<<endl;}
void printvil(vector<int> v){rep(i,0,v.size()){cout<<v[i]<<endl;}}
void printvvi(vector<vector<int>> v){
    rep(i,0,v.size()){
        rep(j,0,v[i].size())cout<<v[i][j];
        cout<<endl;
    }
}
void printvstr(vector<string> v){
    rep(i,0,v.size()){
        cout<<v[i]<<endl;
    }
}

struct S{
    string name;
    double value;
};

signed main (){
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        vector<S> v(n);
        rep(i,0,n){
            cin>>v[i].name;
            v[i].value=0;
            double p,a,b,c,d,e,f,s,m;
            cin>>p>>a>>b>>c>>d>>e>>f>>s>>m;
            double time=(a+b+c+d+e)+(m-1)*(d+e);
            double profit=f*s*m-p;
            v[i].value=profit/time;
        }
        
        auto cmp=[&](S a,S b){
            return (a.value==b.value?a.name<b.name:a.value>b.value);
        };
        sort(all(v),cmp);
        rep(i,0,n){
            cout<<v[i].name<<endl;
        }
        cout<<"#"<<endl;
    }

}
/*
Aで目が出る
Bでわかば
Cで葉
Dで花
Eで実
F個の実
１つあたりSで売れる
M回実をつける
収入効率＝収入/時間


多作期の時、(M-1)(D+E)の時間 + A+B+C+D+Eの時間
収入はF*M*S

降順ソート
*/

