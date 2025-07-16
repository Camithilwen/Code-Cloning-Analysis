#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
char s[1000001],ss[1000000];
int suu[1000000],cnt[1000000];
int main(void)
{
	int i,j,kazu,max=0,len;
	scanf("%s",s);
	kazu=0;
	cnt[kazu]=1;
	ss[kazu]=s[kazu];
	len=strlen(s);
	for(i=1;i<len;i++) {
		if(ss[kazu]==s[i]) cnt[kazu]++;
		else {
			kazu++;
			cnt[kazu]=1;
			ss[kazu]=s[i];
		}
	}
	for(i=0;i<=kazu;i++) {
		if(ss[i]=='O') {
			if(i-1>=0 && i+1<=kazu) {
				if(ss[i-1]=='J' && cnt[i-1]>=cnt[i]) {
					if(ss[i+1]=='I' && cnt[i+1]>=cnt[i]) {
						if(max<cnt[i]) max=cnt[i];
					}
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}