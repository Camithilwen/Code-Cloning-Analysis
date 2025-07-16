#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int k[101];
char s[101];
int main() {
	vector<char>v;
	for (char c = 'a'; c <= 'z'; c++)v.push_back(c);
	for (char c = 'A'; c <= 'Z'; c++)v.push_back(c);
	int n;
	while (scanf("%d", &n), n) {
		rep(i, n)scanf("%d", &k[i]);
		scanf("%s", s);
		int len = strlen(s);
		rep(i, len) {
			s[i] = v[(find(v.begin(), v.end(), s[i]) - v.begin() + 52 - k[i%n]) % 52];
		}
		puts(s);
	}
}