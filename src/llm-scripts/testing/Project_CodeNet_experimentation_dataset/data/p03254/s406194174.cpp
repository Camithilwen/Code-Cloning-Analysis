#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int N, x;
	int a[100];
	long long num = 0LL;
	
	cin >> N >> x;
	for (int i = 0;i < N;i++) cin >> a[i];
	sort(a, a + N);
	int count=0;
	
		for (int k = 0;k < N-1;k++) {
				num += a[k];
				if(num<=x)
				count++;
			
		}
		if (num <= x) {
			if (x - num == a[N - 1]) count++;
		}
		cout << count;
	
	
	
}