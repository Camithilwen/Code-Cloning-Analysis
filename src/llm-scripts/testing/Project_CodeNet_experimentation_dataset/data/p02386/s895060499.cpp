#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> x[100]; int n, t;
bool same(vector<int> a, vector<int> b) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				for(int l = 0; l < 4; l++) {
					string s;
					for(int m = 0; m < i; m++) s += 'N';
					for(int m = 0; m < j; m++) s += 'E';
					for(int m = 0; m < k; m++) s += 'S';
					for(int m = 0; m < l; m++) s += 'W';
					for(int i = 0; i < s.size(); i++) {
        				t = a[0];
        				switch(s[i]) {
        				case 'N':
            				a[0] = a[1];
            				a[1] = a[5];
        					a[5] = a[4];
        				    a[4] = t;
        				    break;
        				case 'E':
        				    a[0] = a[3];
        				    a[3] = a[5];
        				    a[5] = a[2];
        				    a[2] = t;
        				    break;
        				case 'S':
        				    a[0] = a[4];
        				    a[4] = a[5];
        				    a[5] = a[1];
        				    a[1] = t;
        				    break;
        				case 'W':
        				    a[0] = a[2];
        				    a[2] = a[5];
        				    a[5] = a[3];
    					    a[3] = t;
    					   	break;
	    				}
					}
					if(a == b) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		x[i].resize(6);
		for(int j = 0; j < 6; j++) scanf("%d", &x[i][j]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(same(x[i], x[j])) {
				printf("No\n"); return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}