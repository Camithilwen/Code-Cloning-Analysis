#include <bits/stdc++.h>
using namespace std;


int main(){
	long long n;
	long long ans = 1;
	cin >> n;

	vector<int>  fact(10000); //factor container
	
    for(int j = 2; j<=n;j++){
    
    long long num = j;

	for (int i = 2; i <= num; i++) {
		    while (num%i == 0) { // 素数で割り切れなくなるまで割っていく
			     fact.at(i)++; //割った個数を配列に足す
			    num /= i;
		    }
	}

    }

    for(int i = 0; i < 1003; i++){
            ans *= (fact.at(i) + 1);
            ans %= 1000000007;
    }




    cout << ans << endl;

}