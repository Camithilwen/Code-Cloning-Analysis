/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
typedef pair<ll,pair<ll,ll>>plll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define F first
#define S second
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
#define minheap int,vector<int>,greater<int>
#define pb push_back
#define eb emplace_back
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define bug cout<<"BUG"<<endl;
const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)return 0;

    return a/__gcd(a,b)*b;
}

void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)cin>>ara[i];
}
void print(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<endl;
}


int main()
{

    fastread();

    ll i,j,n,m,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r,ans=0;

    bool flag=true;

    string str;

    cin>>n;

    ll ara[n+2],bra[n+2];

    input(ara,n);
    input(bra,n);

    sort(bra,bra+n,greater<ll>());


    for(i=0; i<n; i++)
    {
        if(ara[i]==bra[i])
        {

        bool ok=false;

            for(j=0; j<n; j++)
            {
                if(j<i && ara[i]!=bra[j]  && bra[i]!=ara[j])
                {
                    swap(bra[i],bra[j]);

                    ok=true;
                    break;
                }

                else if(n-j-1>i)
                {
                    p=n-j-1;

                    if(ara[i]!=bra[p])
                    {
                        swap(bra[i],bra[p]);

                        ok=true;
                        break;
                    }
                }
            }

            if(ok==false)
            {
                flag=ok;
                break;

            }


        }
    }

    if(flag)
    {
        for(i=0; i<n; i++)
        {
            if(ara[i]==bra[i])
            {
                flag=false;
                break;
            }
        }
    }

    if(flag==false)
        cout<<"No"<<endl;

    else
    {
        cout<<"Yes"<<endl;

        for(i=0; i<n; i++)
        {
            cout<<bra[i]<<" ";
        }

        cout<<endl;
    }













}

