#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

map<string,int> m;
int memo[99999];
int N;
string s;

void bs(int start,int end){
    //cout<<"aaa1"<<endl;
    int v1,v2,vc;
    int c=(start+end)/2;

    //cout<<"aaa2"<<endl;
    if(memo[start]==-1){
        cout<<start<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            return;
        }
        v1=memo[start]=m[s];
    }else{
        v1=memo[start];
    }

    //cout<<"aaa3"<<endl;
    if(memo[end]==-1){
        cout<<end<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            return;
        }
        v2=memo[end]=m[s];
    }else{
        v2=memo[end];
    }

    //cout<<"aaa5"<<endl;
    if(memo[c]==-1){
        cout<<c<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            return;
        }
        vc=memo[c]=m[s];
    }else{
        vc=memo[c];
    }

    //cout<<"aaa6"<<endl;
    if((c-start)%2==1 && v1==vc){
        bs(start,c);
    }else if((c-start)%2==0 && v1!=vc){
        bs(start,c);
    }else if((end-c)%2==1 && v2==vc){
        bs(c,end);
    }else if((end-c)%2==0 && v2!=vc){
        bs(c,end);
    }
    
}

int main(){
    m["Male"]=0;
    m["Female"]=1;
    m["Vacant"]=2;
    fill(memo,memo+99999,-1);
    cin>>N;

    bs(0,N-1);
}