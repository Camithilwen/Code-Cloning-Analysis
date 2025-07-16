#include <bits/stdc++.h>
#define FOR(I,X,Y) for(long int I=X;I<Y;I++)
#define REP(I,X) for(long int I=X;I>=0;I--)
#define INF 1e9+7
using namespace std;

int main(){
  int a,b,c;
  vector<int> ans;
  while(1){
    cin >> a >> b >> c;
    if(!(a|| b || c))break;
    int N,i,j,k,l;
    cin >> N;
    set<int> unbroken;
    set<int> broken;
    int ii[N],jj[N],kk[N],ll[N];
    FOR(i,0,N)cin >> ii[i] >> jj[i] >> kk[i] >> ll[i];
    FOR(count1,0,N)FOR(count2,0,N){
      int i = ii[count2],j = jj[count2],k = kk[count2],l = ll[count2];
      if(l){
        unbroken.insert(i);
        unbroken.insert(j);
        unbroken.insert(k);
      }
      else{
        if(unbroken.count(i) && unbroken.count(j))broken.insert(k);
        if(unbroken.count(j) && unbroken.count(k))broken.insert(i);
        if(unbroken.count(k) && unbroken.count(i))broken.insert(j);
      }
    }
    FOR(i,1,a+b+c+1){
      if(unbroken.count(i))ans.push_back(1);
      else if(broken.count(i))ans.push_back(0);
      else ans.push_back(2);
    }
  }
  for(auto x:ans)cout << x << endl;
}

