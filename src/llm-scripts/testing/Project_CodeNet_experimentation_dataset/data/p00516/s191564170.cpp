#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main(){

  int n,m,r,q,w=0;
  vector<int> a;
  vector<int> c;

    cin>>n>>m;
    
    for(int i=0; i<n; ++i){
      cin>>q;
      a.push_back(q);
      c.push_back(0);
    }

    for(int i=0; i<m; ++i){
      cin>>q;
      for(int k=0; k<n; ++k)
	if(a[k]<=q){
	  ++c[k];
	  break;
	}
    }
    q=0;
    for(int i=0; i<n; ++i){
      if(q < c[i]) q=c[i],w=i+1;
    }
    cout << w <<endl;

    //    cout<<endl;
    //   for(int i=0; i<n; ++i){
    //     cout<<a[i]<<"  "<<c[i]<<endl;
    //      }
  
  
  return 0;
}

