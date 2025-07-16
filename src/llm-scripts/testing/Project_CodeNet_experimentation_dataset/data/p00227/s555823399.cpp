#include<iostream>
#include<algorithm>
#include<functional>

int *v,m,n,ans=0;

int main(){
	while(true){
		std::cin >> n >> m;
		if(!n && !m)
			return 0;
		v = new int[n];
		for(int i=0 ;i<n; i++)
			std::cin >> v[i];
		std::sort(v,v+n,std::greater<int>());
		if(m!=1)
			for(int i=0; i<n; i++)
				if(!((i+1)%m == 0 && (i+1) >= m))
					ans += v[i];
		std::cout << ans << std::endl;
		delete[] v;
		ans = 0;
	}
}