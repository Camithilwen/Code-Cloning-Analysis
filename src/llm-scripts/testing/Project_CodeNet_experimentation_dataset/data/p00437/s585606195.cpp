#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=1;i<=n;i++)
struct test {
	int i, j, k;
};

vector<test> t;
int p[302];

int main(){
	int a, b, c, n, i, j, k, r;
	while (cin >> a >> b >> c){
		cin >> n;
		t.clear();
		loop(i, a + b + c)p[i] = 2;
		loop(h, n){
			cin >> i >> j >> k >> r;
			if (r == 1){
				p[i] = p[j] = p[k] = 1;
			}
			else{
				t.push_back({ i, j, k });
			}
		}
		for (int h = 0; h < t.size(); h++){
			i = t[h].i; j= t[h].j; k = t[h].k;
			if (p[i] == 1 && p[j] == 1){
				p[k] = 0;
			}
			else if (p[j] == 1 && p[k] == 1){
				p[i] = 0;
			}
			else if (p[k] == 1 && p[i] == 1){
				p[j] = 0;
			}
		}
		loop(i, a + b + c)cout << p[i] << endl;
	}
	return 0;
}