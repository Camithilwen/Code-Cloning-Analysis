#include <bits/stdc++.h>
using namespace std;

int main(){
  int d,g,m;
  m=pow(10,5);
  cin >> d >> g;
  vector<pair<int,int>> v;
  int a,b;
  for(int i=0;i<d;i++){
      cin >> a >> b;
      pair<int,int> p(a,b);
      v.push_back(p);
  }
  for(int i=0; i<(1<<d); i++){
    bitset<10> bit(i);
    bitset<10> check(0);
    int ans,item;
    ans=0;
    item=0;
    for(int j=0; j<d; j++){
      if(bit[j]==1){
        ans+=100*(j+1)*v.at(j).first+v.at(j).second;
        check.set(j,1);
        item+=v.at(j).first;
      }
    }
    int stop = d-1;
    while(true){
      if(ans>=g || stop<0){
        break;
      }
      if(check[stop]==0){
        check.set(stop,1);
        if(ans+100*(stop+1)*(v.at(stop).first-1)>g){
          item+=ceil(1.0*(g-ans)/(100*(stop+1)));
          ans = g;
          break;
        }
        else{
          ans += 100*(stop+1)*(v.at(stop).first-1);
          item+=v.at(stop).first-1;
        }
      }
      stop--;
    }
    if(m>item && ans >= g){
      m=item;
    }
  }
  cout << m << endl;  
}

