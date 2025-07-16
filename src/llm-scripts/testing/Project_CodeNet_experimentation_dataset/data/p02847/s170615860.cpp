#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dob double
int main(){
	string arr[14] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	string a;
	cin>>a;
	int ans = 0;
	bool ok = false;
	for (int i = 0; i<14; i++){
		if (ok){
			ans++;
		}
		if (ok && arr[i] == "SUN"){
			break;
		}
		if (arr[i] == a){
			ok = true;
		}
	}
	cout<<ans;
	return 0;
}
