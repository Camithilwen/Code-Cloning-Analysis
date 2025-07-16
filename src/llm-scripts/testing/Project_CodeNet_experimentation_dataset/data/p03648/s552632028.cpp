#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	long long k;
	cin >> k;
    vector<long long> a(50, 49);
    long long x = (k + 50) / 50, y = (k % 50);
    for(int i = 0; i < 50; i++){
        a[i] += x;
        if(i >= y) a[i] -= y + 1;
    }
	cout << 50 << endl;
    for(int i = 0; i < 49; i++){
        cout << a[i] << " ";
    }
    cout << a[49] << endl;
	return 0;
}
