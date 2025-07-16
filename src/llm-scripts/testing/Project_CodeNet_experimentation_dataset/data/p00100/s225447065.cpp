#include <iostream>
using namespace std;
typedef long long ll;
//vector<pair<bool, ll>> v(4001);
unsigned long long int a[4001];

int main(){
	int n, num, p, q;
	while(cin >> n, n){
		//fill(a, a+4001, 0);
		int f = 1;
		for(int i = 0;i < 4001;i++)a[i] = 0;
		for(int i = 0;i < n;i++){
			cin >> num >> p >> q;
			a[num] += p * q;
			if(a[num]>999999){
                cout << num << endl;
                f = 0;
            }
		}
		if(f)cout << "NA" <<endl;
		/*int f = 1;
		for(int i = 1;i <= 4000;i++)if(a[i] >= 1000000)cout << i << endl, f = 0;
		if(f)cout << "NA" << endl;*/
	}
	return 0;
}

/*
4
1001 2000 520
1002 1800 450
1003 1600 625
1001 200 1220
*/