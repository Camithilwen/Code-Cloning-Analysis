#include <iostream>
#include <stack>
using namespace std;

int main(){
	double l[10], t[10], a, b;
	char c;
	while(cin >> l[0] >> c){
		t[0] = l[0];
		for(int i = 1;i< 10;i++){cin >> l[i] >> c;t[i] = t[i-1] + l[i];}
		cin >> a >> c >> b;
		double tmp = t[9]/(a+b)*a;
		int ans = 1;
		while(tmp > t[ans-1]){
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}