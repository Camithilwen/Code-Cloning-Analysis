#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int tmp=0;
    int ans=0;
    while(tmp<n){
        int tmp2=a[tmp];
        int cnt=0;
        while(tmp<n&&a[tmp]==tmp2){
            tmp++;
            cnt++;
        }
        ans+=cnt%2;
    }
    cout<<ans<<endl;
    return 0;
}