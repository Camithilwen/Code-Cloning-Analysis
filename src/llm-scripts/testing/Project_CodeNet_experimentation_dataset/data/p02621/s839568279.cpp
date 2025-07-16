#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define mod (int) (1e9+7)

// vector<ll>primes;

// void swap(ll &a, ll &b){
// 	ll c=a;
// 	a=b;
// 	b=c;
// }

// bool is_prime(int a){
// 	//bool f=true;
// 	for(int i=2; i*i<=a; i++){
		
// 		if(a%i==0){
// 			return false;
// 		}
		
// 	}
	
// 	return true;
// }




ll gcd(ll a, ll b){
	
	if(b==0){
		return a;
	}
	
	return gcd(b, a%b);
	
}


 
 ll ncr(ll x, ll y){
 	ll ans=1;
 	
 	y=(y > x-y? x-y: y);
 	
 	for(ll i=0; i<y; i++){
 		ans=ans*(x-i);
 		ans=ans/(i+1);
 		ans=ans%mod;
 	}
 
 	
 	return ans;
 }

ll power(ll x, ll y){
    ll ans=1;
    while(y){
        if(y&1){
            ans=ans*x;
            ans=ans%mod;
        }
        
        x=x*x;
        x=x%mod;
        y=y>>1;
    }
    
    return ans;
    
}


 
void solve(){
	
	ll a,res=0; cin>>a;
    
    res+=a+(a*a)+(a*a*a);
    
    cout<<res<<"\n";

   return ;
	
}




int main(){
    ios_base::sync_with_stdio(0);
    
    cin.tie(0);
    
    int t=1;//cin>>t;
    
   
    
    // clock_t begin, end;
    
    // double time_spent;
    
    // begin = clock(); // Time taken till now.
    
    
    while(t--){
    
	  solve();
        
    }
    
 
    
   
   //end= clock(); // Total  Time taken till now.
   
   //time_spent= (end- begin) / CLOCKS_PER_SEC; 
   
   //cout<<time_spent<<"\n";
   
   
   
	
	return 0;
}

