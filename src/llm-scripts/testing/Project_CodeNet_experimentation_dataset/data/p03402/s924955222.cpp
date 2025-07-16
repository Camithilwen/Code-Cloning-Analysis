#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=2e5+9;
char a[109][109];
int main()
{
    FASTINOUT;
    int r,c;
    cin>>r>>c;
    r--,c--;
    char l='.';
    for (int i=1;i<=100;i++){
            if (i==50)
            l='#';
        for (int j=1;j<=100;j++)
            a[i][j]=l;
    }
    for (int i=1;i<=49&&c;i+=2){
        for (int j=1;j<=100&&c;j++){
            if (a[i][j-1]!='#'&&a[i-1][j]!='#'){
            a[i][j]='#';
            c--;
            }

        }
    }
    for (int i=52;i<=100&&r;i+=2){
        for (int j=1;j<=100&&r;j++){
            if (a[i][j-1]!='.'&&a[i-1][j]!='.'){
            a[i][j]='.';
            r--;
            }
        }
    }
    cout<<100<<" "<<100<<endl;
    for (int i=1;i<=100;i++){
        for (int j=1;j<=100;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
