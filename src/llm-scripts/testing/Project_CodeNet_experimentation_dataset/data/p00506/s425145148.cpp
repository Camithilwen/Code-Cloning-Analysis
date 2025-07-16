#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


vector<int> divisor(int n){

  vector<int>res;
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i)res.push_back(n/i);
    }
  }
  return res;
}

int main(void){

  int p,l,n,m;
  vector<int>L,N,M;

  cin >> p;

  if(p==2){
  
    cin >> n >> m;

    N.clear();
    M.clear();

    N=divisor(n);
    M=divisor(m);    

    sort(N.begin(),N.end());
    sort(M.begin(),M.end());

    for(int i=0;i<N.size();i++)
      if(binary_search(M.begin(),M.end(),N[i]))cout << N[i] << endl;
    
  }
  else if(p==3){
    
    cin >> l >> n >> m;

    L.clear();
    N.clear();
    M.clear();

    L=divisor(l);
    N=divisor(n);
    M=divisor(m);    

    sort(L.begin(),L.end());
    sort(N.begin(),N.end());
    sort(M.begin(),M.end());


    for(int i=0;i<N.size();i++)
      if(binary_search(M.begin(),M.end(),N[i]) &&
	 binary_search(L.begin(),L.end(),N[i]))cout << N[i] << endl;
  }  
  return 0;
}