#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int n, ans, out;
	
	string str;
	
	bool base[3];
	
	cin >> n;
	
	for(int loop = 0; loop < n; loop++){
		
		base[0] = false;
		base[1] = false;
		base[2] = false;
		
		ans = 0;
		out = 0;
		
		while(true){
			
			cin >> str;
			
			if(str == "HIT"){
				if(base[2]){
					ans++;
				}
				if(base[1]){
					base[2] = true;
				}else{
					base[2] = false;
				}
				if(base[0]){
					base[1] = true;
				}else{
					base[1] = false;
				}
				base[0] = true;
			}else if(str == "HOMERUN"){
				ans++;
				if(base[2]){
					ans++;
				}
				if(base[1]){
					ans++;
				}
				if(base[0]){
					ans++;
				}
				base[0] = false;
				base[1] = false;
				base[2] = false;
			}else if(str == "OUT"){
				out++;
			}
			if(out >= 3){
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}