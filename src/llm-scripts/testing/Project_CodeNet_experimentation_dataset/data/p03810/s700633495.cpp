#include<bits/stdc++.h>
using namespace std;

bool isEven(int x){return x%2==0;}
bool solve(vector<int> a){
    int n=a.size();
    int oneCnt=count(a.begin(),a.end(),1);
    int evenCnt=count_if(a.begin(),a.end(),isEven);
    if(oneCnt || evenCnt<n-1){
        return !isEven(evenCnt);
    }
    else{
        int g=a[0];
        for(int i=0;i<n;i++) g=__gcd(a[i]/2,g);
        for(int i=0;i<n;i++) a[i]/=(g*2);
        return !solve(a);
    }
}
void output(bool x){
    cout<<(x ? "First" : "Second")<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        output(a[0]!=1);
    }
    else if(n==2){
        output(isEven(a[0]) || isEven(a[1]));
    }
    else{
        output(solve(a));
    }
    
    return 0;
}