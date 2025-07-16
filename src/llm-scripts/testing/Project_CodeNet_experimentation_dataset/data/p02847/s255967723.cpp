#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define mod 1000000007
#define b1(n) __builtin_popcount(n)
vector<int>sie; 
 inline int gEd(int a, int b, int *ax, int *ay) 
{ 
	int x,y;  
	if (a==0) 
	{   *ax=0;
		*ay = 1; 
		return b;
	}
    int g = gEd(b%a,a,&x,&y);
    *ax=y-(b/a)*x; 
	*ay=x; 
	return g; 
}  
inline int mli(int a,int m) //mli(a,m)
{
	int ax,ay;
	     gEd(a,m,&ax,&ay);
	    int val1=(ax%m+m)%m; 
	    return val1;
}
inline int powerm(int a,int n)   //powerm(a,n)
{
	int ans=1;
	while(n>0)
	{
		int last_bit=(n&1);
		if(last_bit)
		ans=((ans%mod)*(a%mod))%mod;
		a=((a%mod)*(a%mod))%mod;
		n=n>>1;
	}
	return ans;
}
inline int power(int a,int n)   //power(a,n)
{
	int ans=1;
	while(n>0)
	{
		int last_bit=(n&1);
		if(last_bit)
		ans=ans*a;
		a=a*a;
		n=n>>1;
	}
	return ans;
}
inline int add(int a,int b)
{
	int s=((a%mod)+(b%mod))%mod;
	return s;
}
inline int sub(int a,int b)
{
	int s=((a%mod)-(b%mod))%mod;
	return s;
}
inline int mul(int a,int b)
{
	int s=((a%mod)*(b%mod))%mod;
	return s;
}
inline int ncr(int n, int k)  //ncr(a,b)
{ 
    int res = 1; 
  
 
    if (k > n - k) 
        k = n - k; 
  
  
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
inline void sieve()   //sieve vector->sie
{
	const int n=10000000;
	bitset<10000000>b;
	b.set();
	b[0]=b[1]=0;
	for(int i =2;i<=n;i++)
	{
		if(b[i])
		{
			sie.push_back(i);
			for(int j=i*i;j<=n;j=j+i)
			b[j]=0;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     string s;
     cin>>s;
   if(s=="SUN"){
	   cout<<"7"<<endl;
	   }
   if(s=="MON"){
	   cout<<"6"<<endl;
	   }
   if(s=="TUE"){cout<<"5"<<endl;}
   if(s=="WED"){cout<<"4"<<endl;}
   if(s=="THU"){cout<<"3"<<endl;}
   if(s=="FRI"){cout<<"2"<<endl;}
   if(s=="SAT"){cout<<"1"<<endl;}
    
		
		
		
    
    
}
