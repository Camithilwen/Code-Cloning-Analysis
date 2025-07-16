//BISMILLAHIR RAHMANIR RAHIM
//SOTO MEAW
//SOTO SONDESH
#include<bits/stdc++.h>

#define ls ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define __ <<" "<<
#define loop(m,n) for(m=0;m<n;m++)
#define rloop(m,n) for(m=n-1;m>=0;m--)
#define case(z) "Case " << z++ << ": "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define quit return 0

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void showmyDS(set<int> ds)
{
    set<int> ::iterator it;
    for (it=ds.begin();it!=ds.end();it++)
    {
        cout << *it << endl ;
    }
    cout << endl;
}
int main()
{
    ls
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //int t,l=1;cin>>t;while(t>0){
        vector<char>s;
        int j;
        string s1;
        cin>>s1;
        loop(j,s1.size()) s.push_back(s1[j]);
        int n,i,c=0;
        cin>>n;
        char a[n];
        int p,index[255];
        memset(index,0,sizeof(index));
        loop(i,n)
        {
            cin>>a[i];
            p=(int)a[i];
            index[p]=1;
        }
        loop(i,s.size())
        {
            p=(int)s[i];
            if(c==1)
                p=48;
again:
            if(index[p]==1 && p==57)
            {
                if(i!=0)
                    p=48;
                else
                    p=49;
                s.push_back('0');
                c=1;
            }
            if(index[p]==1)
            {
                p++;
                c=1;
                goto again;
            }
            else
            {
                cout<<(char)p;
            }
        }
        cout<<endl;
    //t--;}

    quit;
}
