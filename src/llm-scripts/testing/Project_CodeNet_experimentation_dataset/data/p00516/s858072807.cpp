#include <iostream>
using namespace std;

int main() {
int a[1000],t[1000];int n,m;
cin >> n >> m;
for(int i = 0;i<1000;i++){
	a[i]= 0;
	t[i]= 0;
}
for(int i = 0;i<n;i++){
	cin >> a[i];
}
for(int i = 0;i<m;i++){
	int p;
	cin >> p;
	int o = 0;
	while(a[o]>p){o++;}
	t[o]++;
}
int ans = 0;
for(int i = 0;i<n;i++){
	if(t[ans]<t[i]){ans = i;}
}
cout << ans+1 << endl;
	return 0;
}