#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main()
{
    int h,w,n;
    cin >> h >> w >>n;
    int a=max(h,w);
 cout<<(a + n - 1) / a<<endl;
return 0;
}