#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef pair<int,P> Pa;

int a, b, c, n;
vector<Pa> test;
int A[100], B[100], C[100];

int main(){
	while(scanf("%d%d%d", &a, &b, &c)){
		if(a == 0 && b == 0 && c == 0) break;
		vector<Pa> test;
		for(int i = 0; i < 100; i++){
			A[i] = 2; B[i] = 2; C[i] = 2;
		}
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int p, q, r, s;
			scanf("%d%d%d%d", &p, &q, &r, &s);
			q -= a; r -= (a+b);
			p--; q--; r--;
			if(s){
				A[p] = 1;
				B[q] = 1;
				C[r] = 1;
			} else{
				test.push_back(Pa(p,P(q,r)));
			}
		}
		for(int i = 0; i < test.size(); i++){
			if(A[test[i].first]==1&&B[test[i].second.first]==1) C[test[i].second.second] = 0;
			else if(A[test[i].first]==1&&C[test[i].second.second]==1) B[test[i].second.first] = 0;
			else if(B[test[i].second.first]==1&&C[test[i].second.second]==1) A[test[i].first] = 0;
		}
		for(int i = 0; i < a; i++) printf("%d\n", A[i]);
		for(int i = 0; i < b; i++) printf("%d\n", B[i]);
		for(int i = 0; i < c; i++) printf("%d\n", C[i]);
	}
}