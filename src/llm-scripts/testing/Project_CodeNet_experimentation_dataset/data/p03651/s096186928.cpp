#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

int gcdi(int a, int b) {
	if(a<0) a=b;
	if(b<0) b=a;
    if (b == 0) return a;
    return gcdi(b, a%b);
}

int lcmi(int a, int b) {
    return a/gcdi(a, b)*b;
}

int gcdv(vector<int> gv){
	int tmp=gv[0];
	for(int i=1;i<(int)gv.size();i++) tmp=gcdi(tmp, gv[i]);
	return tmp;
}

int lcmv(vector<int> gv){
	int tmp=gv[0];
	for(int i=1;i<(int)gv.size();i++) tmp=lcmi(tmp, gv[i]);
	return tmp;
}

int main(){

	int n, k, gc;
  	vector<int> v;
	map<LLi, int> mp;
  
  	cin>> n >> k;
  	v.resize(n);
  	rep(i, n){
      	cin>> v[i];
      	if(v[i]==k){
          	cout<< "POSSIBLE" <<endl;
          	return 0;
        }
    }
  
  	gc=gcdv(v);
  	
  	rep(i, n){
      	if(v[i]-k>0 && (v[i]-k)%gc==0){
          	cout<< "POSSIBLE" <<endl;
          	return 0;
        }
    }
  
  	cout<< "IMPOSSIBLE" <<endl;
  
	return 0;
}