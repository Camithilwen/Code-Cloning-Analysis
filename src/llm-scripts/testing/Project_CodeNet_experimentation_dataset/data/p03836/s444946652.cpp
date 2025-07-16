#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1[100],s2[100];
string t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    
    int i=0,j=0;
    while(j<(ty-sy))
        {cout << 'U'; j++;}
    while(i<(tx-sx))
       { cout << 'R'; i++;}
    i=0;j=0;
    while(j<(ty-sy))
      { cout << 'D'; j++;}
    while(i<(tx-sx))
        {cout << 'L'; i++;}
    i=0;j=0;
    cout << 'L';
    while(j<(ty-sy)+1)
       { cout << 'U'; j++;}
    while(i<(tx-sx)+1)
        {cout << 'R'; i++;}
    cout << 'D';
    cout << 'R';
    i=0;j=0;
    while(j<(ty-sy)+1)
       { cout << 'D'; j++;}
    while(i<(tx-sx)+1)
        {cout << 'L';i++;}
    cout << 'U';
    
 
    return 0;
}