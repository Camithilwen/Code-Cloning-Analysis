#include <iostream>
#include<algorithm>
using namespace std;

//upper_bound, lower_boundを用いた
//のになぜか通らない・・・

int main(){
	int n;
	long long a;
	if(scanf("%d", &n)==EOF){return 0;}
	
	long long top[n];
	long long center[n];
	long long down[n];
	
	for(int i = 0; i<n; i++){if(scanf("%lld", &a)==EOF){return 0;} top[i] = a;}
	for(int i = 0; i<n; i++){if(scanf("%lld", &a)==EOF){return 0;} center[i] = a;}
	for(int i = 0; i<n; i++){if(scanf("%lld", &a)==EOF){return 0;} down[i] = a;}
	
	
	// top, downをソート
	sort(top, top+n);
	sort(down, down+n);
	//for(int i = 0; i<n; i++){cout << top[i] << ", "<<endl;}
	//for(int i = 0; i<n; i++){cout << down[i] << ", "<<endl;}
	
	long long sum = 0;
	//int ok1, ng1, ok2, ng2, mid;
	int ok1, ok2;

	for(int i = 0; i< n; i++){
		//center[i]より小さいtopの数を探す
		ok1 = lower_bound(top, top+n, center[i]) - top;
		ok2 = upper_bound(down, down+n, center[i]) - down;
		
		//cout << "top[ok1-1]" <<  top[ok1-1] << ", center:"<< center[i] <<", top[ok1]:"<< top[ok1] << endl;
		//cout << "down[ok2-1]:" << down[ok2-1] <<", center:"<< center[i] <<", down[ok2]:" << down[ok2] << endl;
		sum += (long long)ok1 * (long long)(n - ok2);
	}
	printf("%lld\n", sum);
	return 0;
}