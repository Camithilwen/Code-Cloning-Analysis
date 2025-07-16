// Abu Hurayra (HurayraIIT)
// IIT, Jahangirnagar University

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long LL;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef vector<int> vi; 

#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(0);  cin.tie(0);
#define sz(a) int((a).size())
#define space " "
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define pi acos(-1.0)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define MOD 1000000007
#define PRECISION(x) cout << fixed << setprecision(x); 
 
 
int main()
{
    fast_io
    string s ;
    cin >> s ;
    int a = s[0]-'0', b = s[1]-'0' , c = s[2]-'0' , d = s[3]-'0' ;

    if(a+b+c+d==7) cout << a << "+" << b << "+" << c << "+" << d << "=7\n";
    else if(a-b-c-d==7) cout <<a<<"-"<<b<<"-"<<c<<"-"<<d<< "=7\n";
    else if(a+b+c-d==7) cout <<a<<"+"<<b<<"+"<<c<<"-"<<d<< "=7\n";
    else if(a+b-c+d==7) cout <<a<<"+"<<b<<"-"<<c<<"+"<<d<< "=7\n";
    else if(a-b+c+d==7) cout <<a<<"-"<<b<<"+"<<c<<"+"<<d<< "=7\n";
    else if(a-b-c+d==7) cout <<a<<"-"<<b<<"-"<<c<<"+"<<d<< "=7\n";
    else if(a-b+c-d==7) cout <<a<<"-"<<b<<"+"<<c<<"-"<<d<< "=7\n";
    else if(a+b-c-d==7) cout <<a<<"+"<<b<<"-"<<c<<"-"<<d<< "=7\n";

    
    
    return 0;
}


 