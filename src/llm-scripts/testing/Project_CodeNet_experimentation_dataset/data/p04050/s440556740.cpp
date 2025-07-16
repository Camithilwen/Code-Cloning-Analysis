#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], n, cnt, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i  = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i  = 1; i <= m; i++) if (a[i] & 1) cnt ++;
    if (cnt > 2) {
    	puts("Impossible");
    	return 0;
    }
	for (int i = 1; i <= m; i++) 
        if ((a[i] & 1) && (!(a[1] & 1))) swap(a[i], a[1]); 
        else if (a[i] & 1) swap(a[i], a[m]);
	for (int i = 1; i <= m; i++) cout << a[i] << " " ; cout << endl;
	if (!cnt) {
		int ans = m + 2;
		if (a[1] == 2) ans--;
		cout << ans << endl;
		if (a[1] != 2) cout << a[1] - 2 << " " ; cout << "1 ";
		for (int i = 2; i <= m; i++) cout << a[i] << " " ; cout << 1 << endl;
	}
	else if (cnt == 1) {
		int ans = m + 1;
		if (a[1] == 1) ans--;
        cout << ans << endl;
		if (a[1] != 1) cout << a[1] - 1 << " " ; 
		for (int i = 2; i <= m; i++) cout << a[i] << " " ; cout << 1 << endl;
	}
	else if (cnt == 2) {
		int ans = m;
		if (a[1] == 1) ans--;
        cout << ans << endl;
		if (a[1] != 1) cout << a[1] - 1 << " " ; 
		for (int i = 2; i < m; i++) cout << a[i] << " " ; cout << a[m] + 1 << endl;
	}
	return 0;
}
    
