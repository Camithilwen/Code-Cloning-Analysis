#include <iostream>
using namespace std;

int main(){
	double t[10], a, b;
	char c;
	while(cin >> t[0] >> c){
		for(int i = 1;i< 10;i++){cin >> t[i] >> c;t[i] += t[i-1];}
		cin >> a >> c >> b;
		double tmp = t[9]/(a+b)*a;
		int ans = 1;
		while(tmp > t[ans-1])ans++;
		cout << ans << endl;
	}
	return 0;
}