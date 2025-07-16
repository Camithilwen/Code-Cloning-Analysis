#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int power(int a,int b)
{
    if(b==0)
        return 1;
    long long int k=power(a,b/2);
    if(b%2==0)
        return ((k%M)*(k%M))%M;
    else
        return ((k%M)*(k%M)*(a%M))%M;
}
long long int fact(long long int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return ((n%M)*(fact(n-1)%M))%M;

}
int div(int n)
{  int c=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
          if(n/i==i)
            c++;
          else
            c+=2;
        }

    }

    
    return  c;
}
int func(int n)
{
    return (n*(n+1))/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   
   string str;
   cin>>str;
   set<char> s;
   for(int i=0;i<str.length();i++)
   {
      s.insert(str[i]);
   }
   if(s.size()==26)
    cout<<"None";
  else
  { int i=0;

    for(auto it=s.begin();it!=s.end();it++,i++)
    {

        if(*it!=(97+i))
        {
            
            cout<<(char)(97+i);
            return 0;
        }
    }
    if(s.size()<26)
    {
        cout<<char(97+s.size());
    }
  }


 return 0;
}






