/*                                  /   \                                                                   (Hello)//JSM//*/      
/*                                 /*****\                                                                              */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K                                                            */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define EE cout<<"\n"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define mkt make_tuple
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vc vector<char> 
#define vll vector< pair<ll,ll> > 
#define mps map<string ,ll>
#define mpc map<char ,ll>
#define mpl map<ll, ll>
#define pr pair<ll,ll>
#define tpl tuple<ll,ll,ll>
ll containsDigit(ll number, ll digit){while (number != 0){int curr_digit = number % 10;if (curr_digit == digit) return 1;number /= 10;}return 0;}
ll soltn(ll x, ll n) {if(x>=0) return x%n;    else return n+x%n;}
ll pd(ll x,ll y){if(x%y==0) return x/y;else return x/y+1;}
ll coda(ll n,ll d){ll count=0;while(n!=0){if(n%10==d)count++;n/=10;}return count;}
ll mdls(ll x){return max(x,-x);}
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x%MOD*x%MOD)%MOD;if(p%2==0) return x;else return (x*n)%MOD;}
ll isSubstr(string s1, string s2) {   ll M = s1.length();    ll N = s2.length();  for (ll i = 0; i <= N - M; i++) { ll j; for (j = 0; j < M; j++) if (s2[i + j] != s1[j])  break;         if (j == M) return i;   } return -1; } 
//s2>s1;if(not) rtrn -1;

ll maxSubArraySum(ll a[], ll size) 
{ 
   ll max_so_far = a[0]; 
   ll curr_max = a[0]; 
  
   for (ll i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 
   
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll tt=1;

//	   cin>>tt;
	      while(tt--)
{

/*
3 2 3*/
ll n,j,i;
ll a[3];
fo(i,3)
cin>>a[i];
sort(a,a+3);
cout<<a[0]+a[1];
ee;	
	
}
return 0;
}











