#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
typedef long long ll;

int n;
char s[40];
std::map<std::pair<std::string,std::string>,int> C;

int main()
{
    scanf("%d%s",&n,s);
    std::reverse(s+n,s+(n<<1));
    for(int i=0;i<(1<<n);++i)
    {
        std::string a,b;
        for(int j=0;j<n;++j)
            if(i>>j&1)a+=s[j];
            else b+=s[j];
        ++C[std::make_pair(a,b)];
    }
    ll Ans=0;
    for(int i=0;i<(1<<n);++i)
    {
        std::string a,b;
        for(int j=0;j<n;++j)
            if(i>>j&1)a+=s[n+j];
            else b+=s[n+j];
        Ans+=C[std::make_pair(a,b)];
    }
    printf("%lld\n",Ans);
    return 0;
}