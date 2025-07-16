#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define L first
#define R second
using namespace std;

int qmin(int a, int b){
	return (a < b) ? a : b;
}
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int n;
pair<int, int> seg[100100];

int len(int l, int r){
	return qmax(r-l+1, 0);
}

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &seg[i].L, &seg[i].R);
	int lmax = seg[0].L, lmax_pos = 0, rmin_2nd = seg[0].R;
	int rmin = seg[0].R, rmin_pos = 0;
	rep(i, n){
		if(seg[i].L > lmax){
			lmax = seg[i].L;
			lmax_pos = i;
			rmin_2nd = seg[i].R;
		}
		if(seg[i].L == lmax) lmax_pos = -1;
		if(seg[i].R < rmin){
			rmin = seg[i].R;
			rmin_pos = i;
		}
		if(seg[i].R == rmin) rmin_pos = -1;
	}
	int ans = len(lmax, rmin) + len(seg[0].L, seg[0].R);
	rep(i, n){
		ans = qmax(ans, len(lmax, rmin) + len(seg[i].L, seg[i].R));
	}
	if(lmax_pos < 0 || lmax_pos != rmin_pos){
		sort(seg, seg+n);
		for(int i = n-1; i > 0; i--){
			rmin_2nd = qmin(rmin_2nd, seg[i].R);
			ans = qmax(ans, len(lmax, rmin_2nd) + len(seg[i-1].L, rmin));
		}
	}
	cout << ans << endl;
	return 0;
}