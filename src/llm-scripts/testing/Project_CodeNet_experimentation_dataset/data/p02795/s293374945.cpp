#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,N,ans=0;
    cin>>H>>W>>N;
    if (H>W) cout<<(N-1)/H+1<<endl;
    else cout<<(N-1)/W+1<<endl;

    return 0;
}