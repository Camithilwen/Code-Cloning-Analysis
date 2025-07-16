    #include<cstdio>
    using namespace std;
    #define N 1050000
    #define mod 1000000007
    int dp[N][2],n,s[N],las[N],k=20,sn;
    int main()
    {
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    	for(int i=0;i<1<<k;i++)dp[i][0]=1;
    	for(int i=1;i<n;i++)
    	{
    		s[i]^=s[i-1];
    		dp[s[i]][0]=(dp[s[i]][0]+1ll*dp[s[i]][1]*(sn-las[s[i]]))%mod;
    		dp[s[i]][1]=(dp[s[i]][1]+dp[s[i]][0])%mod;
    		las[s[i]]=sn;
    		if(s[i]==0)sn++;
    	}
    	s[n]^=s[n-1];
    	if(s[n])
    	{
    		int ans=0;
    		dp[s[n]][0]=(dp[s[n]][0]+1ll*dp[s[n]][1]*(sn-las[s[n]]))%mod;
    		printf("%d\n",dp[s[n]][0]);
    	}
    	else
    	{
    		int ans=0;
    		for(int i=1;i<1<<k;i++)
    		ans=(ans+dp[i][1])%mod;
    		int tp=1;
    		for(int i=1;i<=sn;i++)tp=tp*2%mod;
    		printf("%d\n",(ans+tp)%mod);
    	}
    }