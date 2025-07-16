#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
#define INF 0xFFFFFF
#define ull unsigned long long
#define ll long long
#define ms(x,a) memset(x,a,sizeof(x))
#define endl "\n"
#define M(a,b)  (a+b)/2
#define L(x) 2*x
#define R(x) 2*x+1
using namespace std;
typedef pair<int,ll> ii;
typedef pair<int,ii> iii;
int Move[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
/*
    nothing at all
*/
int scr(string s){
    int score=INF;
    for(int i=0;i<s.size()-1;i++){
        score=min(score,abs(s[i]-s[i+1]));
    }
    //cout<<s<<" "<<score<<endl;
    return score;
}
int main(){
    int n;
    cin>>n;
    int arr[2*n+10];
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(2*n));
    int rzlt=0;
    for(int i=0;i<n;i++){rzlt+=arr[2*i];}
    cout<<rzlt;
    return 0;
}
