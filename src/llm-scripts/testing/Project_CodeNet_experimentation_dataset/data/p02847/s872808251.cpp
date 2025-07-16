/*
** author:mahmoud magdy
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

inline int D()
{
    int m ;
    cin>>m;
    return m ;
}
inline ll lD()
{
    ll m ;
    cin>>m;
    return m ;
}
inline double dD()
{
    double m;
    cin>>m;
    return m;
}
void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
int main()
{
    fast();
    string s[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string s1;
    cin>>s1;
    int day;
    for(int i=0;i<7;i++){
        if(s[i]==s1){
            day=i+1;
            break;
        }
    }
    cout<<7-(day-1)<<endl;
}
