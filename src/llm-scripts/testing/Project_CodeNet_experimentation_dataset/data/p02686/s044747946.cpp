#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define ff first
#define ss second

char s[1000010];

bool comp(ii a, ii b){
	return a.ss > b.ss;
}
int32_t main(){
	int n;
	scanf("%d", &n);
	vector<ii> v1, v2;
	for(int z=0; z<n; ++z){
		scanf("%s", s);
		int q = 0;
		int tam = int(strlen(s));
		int a=0, b=0;
		for(int i = 0; i<tam; ++i){
			if(s[i]==')'){
				if(q>0) --q;
				else ++b;
			}
			else ++q;
		}
		a = q;
		if(a>b) v1.emplace_back(a, b); 
		else v2.emplace_back(a, b); 
	}
	sort(v1.begin(), v1.end(), comp);
	sort(v2.begin(), v2.end());
	int q = 0;
	for(auto x:v2){
		int a = x.ff;
		int b = x.ss;
		if(a>q){
			printf("No\n");
			return 0;
		}
		q-=a;
		q+=b;
	}
	for(auto x:v1){
		int a = x.ff;
		int b = x.ss;
		if(a>q){
			printf("No\n");
			return 0;
		}
		q-=a;
		q+=b;
	}
	if(q==0)
		printf("Yes\n");
	else
		printf("No\n");
}
