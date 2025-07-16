#include <iostream>
#include <queue>

int main(){
	std::priority_queue<int> p;
	
	int n, m;
	int price;
	while(std::cin >> n >> m){
		int sum_price = 0;
		if(n == 0 && m == 0) break;
		//input
		for(int i = 0; i < n; ++i){
			std::cin >> price;
			p.push(price);
		}
		//袋詰め
		while(!p.empty()){
			for(int i = 1; i <= m && !p.empty(); ++i){
				if(i != m){
					sum_price += p.top();
					p.pop();
				}
				else{
					p.pop();
				}
			}
		}
		std::cout << sum_price << std::endl;
	}
}