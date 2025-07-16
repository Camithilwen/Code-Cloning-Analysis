#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n ;
LL ar[200005] ;

pair<LL,LL> BS(const int lower, const int upper){
	LL extra ;
	if(lower == 0)	extra =  0 ;
	else 	extra = ar[lower - 1] ;

	int l = lower, u = upper, mid, indx = -1 ;
	LL min_diff = LLONG_MAX ;

	while(l <= u){
		mid = (l + u) / 2 ;
		LL left = ar[mid] - extra ;
		LL right = ar[upper] - ar[mid] ;
		
		if(abs(left - right) < min_diff){
			min_diff = abs(left - right) ;
			indx = mid ;
		}
		
		if(left == right)
			break ;
		else if(left > right)
			u = mid - 1 ;
		else 
			l = mid + 1 ;
	}

	return {ar[indx] - extra, ar[upper] - ar[indx]} ;
}

int main(){

	cin >> n >> ar[0] ;
	for(int i = 1 ; i < n ; i++){
		cin >> ar[i] ;
		ar[i] += ar[i-1] ;
	}
	
	LL ans = LLONG_MAX ;
	for(int i = 1 ; i + 2 < n ; i++){
		pair<LL,LL> p1 = BS(0, i) ;
		pair<LL,LL> p2 = BS(i + 1, n - 1) ;
		ans = min(ans, ( max(p1.first, max(p1.second, max(p2.first, p2.second)))
					- min(p1.first, min(p1.second, min(p2.first, p2.second))) )) ;
	}
	cout << ans << endl ;

	return 0;
}