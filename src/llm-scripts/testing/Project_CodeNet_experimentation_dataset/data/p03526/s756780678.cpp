#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

struct person{
	long long h;
	long long p;
};

int main(){
	int n;
	int ans=0;
	std::vector<person> list;
	std::vector<long long> dpList;

	std::cin>>n;
	list.resize(n);
	dpList.resize(n+1, -1);
	dpList[0]= 0;

	for(int i=0; i<n; i++)
		std::cin>>list[i].h>>list[i].p;
	
	std::stable_sort(list.begin(), list.end(), [](const person& x, const person& y){return x.p+ x.h< y.p + y.h;});

	for(int i=0; i<n; i++){
		for(int j=i; j>=0; j--){
			if(dpList[j]==-1)
				continue;

			if(dpList[j]>list[i].h)
				continue;

			if(dpList[j+1]==-1)
				dpList[j+1]=dpList[j]+list[i].p;
			else
				dpList[j+1]=std::min(dpList[j]+list[i].p, dpList[j+1]);
		}
	}

	for(int i=n; i>=0; i--){
		if(dpList[i]!=-1){
			ans= i;
			break;
		}

	}

	std::cout<<ans<<std::endl;

	return 0;
	
}