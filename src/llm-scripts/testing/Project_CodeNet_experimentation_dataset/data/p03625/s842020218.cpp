#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define line cout<<"here - "<<__LINE__<<"\n";
#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
#define infi INT_MAX
#define rinfi INT_MIN
#define inf LLONG_MAX
#define rinf LLONG_MIN
#define ff first
#define ss second
using namespace std;
main()
{
    fast
    int tc=1,i,j,k;
//    cin>>tc;
    while(tc--)
    {
       int a;
       cin>>a;
       int aa[a];
       map<int,int>mp;
       for(i=0;i<a;i++)
        cin>>aa[i],mp[aa[i]]++;
        sort(aa,aa+a);
        vector<int>tmp;
        for(i=a-1;i>=0;i--)
        {
            while(mp[aa[i]]>=2)
            {
                tmp.push_back(aa[i]);
                mp[aa[i]]-=2;
            }
        }
        if(tmp.size()<2)
            cout<<0<<endl;
        else cout<<tmp[0]*tmp[1]<<endl;

    }

}


