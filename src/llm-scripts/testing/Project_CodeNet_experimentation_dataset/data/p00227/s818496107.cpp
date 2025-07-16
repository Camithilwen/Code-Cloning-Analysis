#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int veg[1024];
	int sum;

	while (1){
		sum = 0;
		scanf("%d%d", &n, &m);

		if (n == 0 && m == 0){
			break;
		}

		for (int i = 0; i < n; i++){
			scanf("%d", &veg[i]);
		}

		sort(veg, veg + n);
		reverse(veg, veg + n);

		for (int i = 0; i < n; i++){
			if ((i + 1) % m != 0){
				sum += veg[i];
			}
		}

		cout << sum << endl;
	}

	return (0);
}