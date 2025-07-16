#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

const int MAX_V=102;
int vote[MAX_V];

int main(){ _;
  int n,q,m,tmp,result,resultCount;
  while(cin>>n>>q,(n|q)!=0){
    REP(i,MAX_V) vote[i]=0;
    REP(i,n){
      cin>>m;
      REP(j,m){
	cin>>tmp;
	vote[tmp]++;
      }
    }
    result=0;
    resultCount=q-1;
    REP(i,MAX_V){
      if(vote[i]>resultCount){
	result=i;
	resultCount=vote[i];
      }
    }
    cout<<result<<endl;
  }
}