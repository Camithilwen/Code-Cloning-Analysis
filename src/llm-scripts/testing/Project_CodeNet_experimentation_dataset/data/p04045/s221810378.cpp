#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    ll k,i,j;
    string n,m="0";
    vt<ll> dislike;
    cin>>n>>k;
    m=m+n;
    read(dislike,k);
    fd(i,m.length()-1,1,1)
        while(find(dislike.begin(),dislike.end(),m[i]-'0')!=dislike.end()){
            j=i;
            if (m[j]!='9'){
                m[j]=((m[j]-'0'+1)%10)+'0';
                f(j,j+1,m.length(),1)
                    m[j]='0';
                i=m.length()-1;
            }
            else{
                while(m[j]=='9'){
                    m[j]='0';
                    j--;
                }
                m[j]=((m[j]-'0'+1)%10)+'0';
                i=m.length()-1;
            }
        }
    if (m[0]!='0'){
        while(find(dislike.begin(),dislike.end(),m[0]-'0')!=dislike.end()){
            m[0]=((m[0]-'0'+1)%10)+'0';
        }
        f(j,1,m.length(),1)
            m[j]='0';
        fd(i,m.length()-1,1,1)
            while(find(dislike.begin(),dislike.end(),m[i]-'0')!=dislike.end()){
                j=i;
                if (m[j]!='9'){
                    m[j]=((m[j]-'0'+1)%10)+'0';
                    f(j,j+1,m.length(),1)
                        m[j]='0';
                    i=m.length()-1;
                }
                else{
                    while(m[j]=='9'){
                        m[j]='0';
                        j--;
                    }
                    m[j]=((m[j]-'0'+1)%10)+'0';
                    i=m.length()-1;
                }
            }
    }
    if (m[0]!='0')
        cout<<m<<endl;
    else
        cout<<m.substr(1)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}