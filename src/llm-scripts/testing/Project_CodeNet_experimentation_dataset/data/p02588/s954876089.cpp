#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mp make_pair
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    ll n, i, j, sum=0, ans=0, a, b, c, MOD=200003, sz, num, cur;
    string s;
    map< pair<ll,ll>, ll > mpp; mpp.clear();
    cin >> n;
    ffr(j,0,n){
        cin >> s;
        i=0; sz=s.size(); num=0;

        while(i<sz && s[i]!='.'){
            cur = s[i]-'0';
            num*=10; num+=cur;
            i++;
        }
        i++;
        a=b=c=0;
        while(i<sz){
            cur = s[i]-'0';
            num*=10; num+=cur;
            i++;
            c++;
        }
        while(1){
            if(num&1) break;
            else{
                num>>=1;
                a++;
            }
        }
        while(1){
            if(num%5>0) break;
            else{
                num/=5;
                b++;
            }
        }
        mpp[mp(a-c,b-c)]++;
    }
    for(auto i:mpp){
        //if(i.first.first<0) continue;
        for(auto j:mpp){
            //if(j.first.first>0) continue;
            if(i==j) continue;
            if(i.first.first+j.first.first>=0 && i.first.second+j.first.second>=0) ans+=(i.second*j.second);
        }
        if(i.first.first>=0 && i.first.second>=0)
        {
            cur = i.second;
            ans+= (cur*cur-cur);
        }
    }

    cout << ans/2 << endl;
}
