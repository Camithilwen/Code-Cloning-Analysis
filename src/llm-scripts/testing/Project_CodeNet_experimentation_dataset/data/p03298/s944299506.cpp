#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 0x7fffffff
#define lli long long int
int n,len;
char c[50];

vector<set<pair<int,int> > > trie;
vector<lli> s;

inline int fd(int now,int k){
	if(trie[now].empty()) return 0;
	set<pair<int,int> >::iterator it=trie[now].lower_bound(make_pair(k,0));
	if(it==trie[now].end()) return 0;
	if(it->first!=k) return 0;
	return it->second;
}
inline int upd(){
	set<pair<int,int> > sss;
	sss.clear();
	trie.push_back(sss);
	s.push_back(0);
	return trie.size()-1;
}

int t[50],cnt;
inline void add(){
	int now=0,temp=0;
	for(int i=1;i<=n;i++){
		int pos=t[i],nxt=fd(now,pos);
		if(!nxt) nxt=upd(),trie[now].insert(make_pair(pos,nxt));
		now=nxt;
	}
	s[now]++;
	return;
}
inline unsigned lli query(){
	int now=0;
	for(int i=1;i<=n;i++){
		int pos=t[i],nxt=fd(now,pos);
		if(!nxt) return 0;
		now=nxt;
	}
	return s[now];
}

unsigned lli ans=0;
const lli vl[20]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};

int main(){
	scanf("%d",&n);
	len=n<<1;
	cin>>c+1;
	upd();
	for(int i=0;i<=vl[n+1]-1;i++){
		cnt=0;
		for(int j=1;j<=n;j++) if((i&vl[j])==vl[j]) t[++cnt]=c[j]-'a';
		for(int j=1;j<=n;j++) if((i&vl[j])==0) t[++cnt]=c[j]-'a'+26;
		add();
	}
	for(int i=0;i<=vl[n+1]-1;i++){
		cnt=0;
		for(int j=1;j<=n;j++) if((i&vl[j])==0) t[++cnt]=c[len-j+1]-'a';
		for(int j=1;j<=n;j++) if((i&vl[j])==vl[j]) t[++cnt]=c[len-j+1]-'a'+26;
		ans+=query();
	}
	cout<<ans<<endl;
	return 0;
}