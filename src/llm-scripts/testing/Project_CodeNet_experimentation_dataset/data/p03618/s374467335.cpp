#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[200005];
int n,cnt[26];
ll ans=0;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
	ans=1;
	for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)ans+=1ll*cnt[i]*cnt[j];
	printf("%lld\n",ans);
	return 0;
}