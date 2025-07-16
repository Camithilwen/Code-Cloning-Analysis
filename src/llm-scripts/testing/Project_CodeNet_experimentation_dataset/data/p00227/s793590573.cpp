#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	int n,m;

	while(std::cin >> n >> m){
		
		if(n == 0 && m == 0) return 0;

		std::vector<int> a(n);

		for(int i = 0; i < n; ++i){
			std::cin >> a[i];
		}

		std::sort(a.begin(), a.end(), std::greater<int>());//降順

		int cost = 0;

		for(int i = 0; i < n; ++i){
			if((i+1) % m != 0) cost += a[i];//mの倍数番目に高い野菜を無料にする
		}

		std::cout << cost << std::endl;
	}
}
