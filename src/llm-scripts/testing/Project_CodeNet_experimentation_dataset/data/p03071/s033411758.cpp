#include<bits/stdc++.h> 

using namespace std;

int main()
{
    int a,b,c,d;
    string A,B;
    cin >> a >> b;
    c = max(a,b);
    d = min(a,b);
    int e = c;
    c--;
    c = max(c,d);
    e += c;
    
    cout <<e<<endl;

    return 0;
}