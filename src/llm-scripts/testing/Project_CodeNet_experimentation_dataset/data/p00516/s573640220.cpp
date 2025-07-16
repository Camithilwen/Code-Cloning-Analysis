#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <string.h>
#include <functional>

using namespace std;

int a[1010];
int b[1010];
int c[1010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i]>=a[j]){
                c[j]++;
                break;
            }
        }
    }
    int max=0;int ans=-1;;
    for(int i=0;i<n;i++){
        if(c[i]>max){
            max=c[i];
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}