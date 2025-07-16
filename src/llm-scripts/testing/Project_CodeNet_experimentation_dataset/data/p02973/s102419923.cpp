#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
const int inf =2e9;
int N,top=0;
int st[maxn];
int main(){
    cin>>N;
    st[top]=-inf;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        x=-x;
        if(x>=st[top])st[++top]=x;
        else{
            int l=1,r=top;
            while(l<=r){
                int mid=(l+r)/2;
                if(x>=st[mid])l=mid+1;
                else r=mid-1;
            }
            st[l]=x;
        }
    }
    cout<<top<<endl;
}
