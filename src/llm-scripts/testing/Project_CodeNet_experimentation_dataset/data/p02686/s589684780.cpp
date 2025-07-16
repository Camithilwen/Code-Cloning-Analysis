#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<int,int> >bara,koma;

bool comp1(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.second<b.second);
}

bool comp2(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return (a.first>b.first);
}

int main()
{
    int t;
    cin>>t;
    int open,close;
    while(t--)
    {
        string s;
        cin>>s;
        open=0;
        close=0;
        for(char c : s)
        {
            if(c=='(')
            {
                open++;
            }
            else
            {
                if(open)
                    open--;
                else
                    close++;
            }
        }
        if(open>=close)
            bara.push_back({open,close});
        else
            koma.push_back({open,close});
    }

    sort(bara.begin(), bara.end(),comp1);
    sort(koma.begin(),koma.end(),comp2);

    bara.insert(bara.end(),koma.begin(),koma.end());

    int ans=0;
    for(auto x : bara)
    {
        ans-=x.second;
        if(ans<0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        ans+=x.first;
    }
    if(ans==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
