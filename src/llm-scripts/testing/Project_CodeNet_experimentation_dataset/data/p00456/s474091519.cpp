#include <iostream>
using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
	ios::sync_with_stdio(false);
	
	int w[3]={}, k[3]={};
	int a;
	
	rep(i, 10) {
		cin >> a;
		if(w[0]<a) {
			w[2]=w[1];
			w[1]=w[0];
			w[0]=a;
		}else if(w[1]<a) {
			w[2]=w[1];
			w[1]=a;
		}else if(w[2]<a) {
			w[2]=a;
		}
	}
	
	rep(i, 10) {
		cin >> a;
		if(k[0]<a) {
			k[2]=k[1];
			k[1]=k[0];
			k[0]=a;
		}else if(k[1]<a) {
			k[2]=k[1];
			k[1]=a;
		}else if(k[2]<a) {
			k[2]=a;
		}
	}
	
	rep(i, 2) {
		w[2]+=w[i];
		k[2]+=k[i];
	}
	
	cout << w[2] << " " << k[2] << endl;
	
	return 0;
}