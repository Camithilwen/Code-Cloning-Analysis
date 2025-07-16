#include<bits/stdc++.h>
using namespace std;

#define ran 1001001

struct Node {
	int pre, det, suf;
	Node() {}
} info[ran];

int n;
char s[ran];

Node analysis() {
	int len = strlen(s);
	
	int h = 0;
	int mi = 0;
	for(int i=0;i<len;i++) {
		if(s[i]=='(') h++;
		else h--;
		mi = min(mi, h);
	}
	
	Node res;
	res.pre = -mi;
	res.det = h;
	res.suf = res.pre + res.det;
	return res;
}

int cmp(const Node &a, const Node &b) {
	bool fa = (a.det>=0), fb = (b.det>=0);
	if(fa!=fb) return fa;
	if(fa) return a.pre<b.pre;
	return a.suf > b.suf;
}

bool chk() {
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += info[i].det;
	if(sum!=0) return false;
	
	sort(info, info+n, cmp);
	
	int cur = 0;
	for(int i=0;i<n;i++) {
		if(cur<info[i].pre) return false;
		cur += info[i].det;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) {
		scanf("%s", s);
		info[i] = analysis();
	}
	
	puts(chk() ? "Yes" : "No");
	
	return 0;
}