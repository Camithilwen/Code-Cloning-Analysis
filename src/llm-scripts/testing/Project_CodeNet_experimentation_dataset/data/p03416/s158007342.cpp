#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++){
        int s[5];
        int x=i;
        for(int j=0;j<5;j++){
            s[j]=x%10;
            x/=10;
        }
        if(s[0]==s[4]&&s[1]==s[3])ans++;
    }
    cout<<ans<<endl;
    return 0;
}