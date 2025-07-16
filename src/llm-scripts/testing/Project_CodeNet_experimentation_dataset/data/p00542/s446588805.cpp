#include <bits/stdc++.h>
#define ii pair <int , int>
#define is pair <int, string>
#define ic pair <int, char>
#define ll long long
#define mx 100000
#define sf scanf
#define sf(n) scanf("%d",&n)
#define pf printf
using namespace std;
vector <int> v;

/*int intConvert(string s){
    int n;
    stringstream geek(s);
    geek >> n;
    return n;
}*/

/*string strConvert(int n){
    string s;
    stringstream ss;
    ss << n;
    s=ss.str();
    return s;
}*/


int main(){
    int n=4;
    while(n--){
        int a;
        sf(a);
        v.push_back(a);
    }
    int a,b;
    sf(a),sf(b);
    int Max=max(a,b);

    sort(v.begin(),v.end());
    int sum=0;
    for(int i=3; i>=1; i--){
        sum+=v[i];
    }
    pf("%d\n",(sum+Max));

    return 0;
}

