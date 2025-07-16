#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    string s;

    cin>> s;

    if(s[0] != 'A' )
    {
        cout<< "WA\n";
        return 0;
    }

    int cn= 0;

    for(int i=1; i<s.size(); i++)
    {
        if (i>=2 && i<= (s.size() -2 ))
        {
            if(s[i]== 'C')
            {
                cn++;
                continue;
            }
        }

        if(s[i]< 'a' || s[i] > 'z'  || cn>1)
        {
            {
                cout<< "WA\n";
                return 0;
            }
        }
    }


    cout<< (cn==1?  "AC\n" : "WA\n");

    return 0;
}

