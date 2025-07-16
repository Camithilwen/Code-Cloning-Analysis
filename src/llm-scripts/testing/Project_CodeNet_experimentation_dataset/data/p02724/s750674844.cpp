#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
/*int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
//	for(int i=0;i<n;i++) cout<<a[i];
	int sum=0;
	for(int i=n-1;i>1;i--)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i]==a[j]) continue;
			for(int k=j-1;k>=0;k--)
			{
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] < (a[k] + a[j])) 
				{
					sum++;
				}
				
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] >= (a[k] + a[j])) 
				{
					break;
				}
				
			}
		}
	}
	
	cout<<sum;
}

int main()
{
	int n,d,ans=0;
	cin>>n>>d;
	while(n--)
	{
		int a,b; cin>>a>>b;
		long long int fl=a*a + b*b;
		float sum=sqrt(fl);
		if(sum<=d) ans++;
		
	}
	cout<<ans;
}
int main()
{
	int n,k; cin>>n>>k;
	int a[n],sum=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<k;i++) sum+=a[i];
	cout<<sum; 
}

int main()
{
	int n,k; cin>>n>>k;
	k%2==0 and k>=2*n and k<=4*n ? cout<<"Yes" : cout<<"No";
}

int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	unsigned long long ans=1,ANS;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		ans*=a[i];
		ANS=ans;
		while(ANS)
		{
			v.push_back(ANS%10);
			ANS/=10;
		}
		if(v.size()>1000000000000000000)
		{
			cout<<"HRE";
			cout<<"-1";
			return 0;
		}
		v.clear();
	}
	cout<<ans;
}

int main()
{
	int n; cin>>n;
	string s; cin>>s;
	if(s.size()<=n) cout<<s;
	else {
		
	for(int i=0;i<n;i++) cout<<s[i];
	cout<<"...";
}}

int main()
{
	long long int a,b,c,d; cin>>a>>b>>c>>d;
	long long int sum=0,count=0;
	if(a<=d)
	{
		sum+=a;
		d-=a;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(b<=d)
	{
		
		d-=b;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(c<=d)
	{
		sum-=c;
		d-=c;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<sum-d;
		return 0;
	}
	
	
}


int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) a[i]=0;
	while(k--)
	{
		int d; cin>>d;
		for(int i=0;i<d;i++) 
		{
			int x; cin>>x;
			a[x-1]++;
		}
	}
	//cout<<a[2];
	int ans=0;
	for(int i=0;i<n;i++) if(a[i]==0) ans++; cout<<ans;
}
int main()
{
	long long int n,year=0; cin>>n;
	int a=100;
	while(a<n)
	{
		float aa=(1.0/100)*a;
		a+=floor(aa);
		year++;
	}
	cout<<year;
}
int main()
{
	long long int n,m; cin>>n>>m;
	long long int sum=0,a[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];	
	} 
	sort(a,a+n,greater<int>());
	float min=sum*1.0/(4*m);
	a[m-1]<min?cout<<"No": cout<<"Yes\n";	
}*/

int main()
{
	int n; cin>>n;
	long long sum=(n/500)*1000 + ((n-(n/500)*500)/5)*5;
	cout<<sum;
}
