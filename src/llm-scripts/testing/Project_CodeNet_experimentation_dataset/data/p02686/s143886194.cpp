#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 998244353;
struct node{
    int l,r;
};
const int N = 1e6+7;
string s[N];
int n;
vector<node>a;
vector<node>b;
bool cmp(node x,node y)
{
    return x.r<y.r;
}
bool cmp1(node x,node y){
    return x.l<y.l;
}
int main()
{
    cin >> n;
    for(int i = 1;i<=n;++i)
    {
        cin >>s[i];
        int len  =s[i].length();
        int l = 0,r = 0;
        for(int j = 0;j<len;++j)
        {
            if(s[i][j]=='(')++l;
            else if(l)--l;
            else ++r;
        }
        if(l>=r) a.push_back({l,r});
        else b.push_back({l,r});
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp1);
    int sum = 0,ok = 0;
    for(int i = 0;i<a.size();++i)
    {
        sum-=a[i].r;
        if(sum<0)
        {
            ok = 1;
            break;
        }
        sum+=a[i].l;
    }
    int sum1 = 0;
    for(int i = 0;i<b.size();++i)
    {
        sum1-=b[i].l;
        if(sum1<0)
        {

            ok = 1;
            break;
        }
        sum1+=b[i].r;
    }
    if(ok)
        puts("No");
    else
    {
        if(sum==sum1)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
