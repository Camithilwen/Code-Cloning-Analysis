#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;
using namespace __gnu_pbds;

// #define  part ..
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
//#define maxx 200006
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


// end of #define 

// define globals ...
const int maxx = 2e6+26;

//write function from here ...

vector <  int > arr;



void prime () {
	
	bool vis[maxx];
	memset ( vis, 0 , sizeof (vis) );
	
	for (  ll i = 2; i*i <=maxx; i++){
		
		
		if( vis[i] == 0 ){
			
			for( ll j = i*i; j<maxx ; j+= i){
				
				vis[j] =1 ;
				
			}
			
		} 
		
		
	}
	
	for ( int i= 2; i < maxx; i++){
		
		if( vis[i]== 0){
			arr.pb( i);
		}
		
	}
	
	
}




int Main(){

prime();
ll  a,b;
cin>>a>>b;


int nn = arr.size();


ll temp  =a;
int  i = 0 ;
set < ll > st ;
map< ll , int   > mp1 ,mp2;

//int j = 0 ;
 //for(auto it : arr ) {
	 //if( j > 100)
	 //break;
     //else
     //{cout<<it<<" ";j++;
	 //}
	//}
while(i < nn  && temp > 1){
	if( temp%arr[i]==0)
	{
		mp1[arr[i]]= 1;
		st.insert( arr[i]);
	}
	while(temp%arr[i] == 0 )
	{
		
		temp/=arr[i];
		
	}
	
	i++;
	
	
}
if(temp > 1)
{
	mp1[temp ] = 1;
	st.insert(temp);
} 

temp = b;
i =0 ;

while(i < nn && temp > 1){
	if( temp%arr[i]==0){
	mp2[arr[i]]= 1;
	st.insert(arr[i]);
}
	
	while(temp%arr[i] == 0 )
	{
		
		temp/=arr[i];
		
	}
	
	i++;
	
	
}
if(temp > 1)
{
	mp2[temp ] = 1;
	st.insert(temp);
}

int cnt =1;

for( auto it : st ) {
	
	
	if(mp1 [it]  && mp2[it] ){
	cnt++;
	} 
	
}


cout<<cnt<<endl;


return 0;

}






int main(){
 quick;
int t =1; 
//cin>>t;
while(t-- )
 Main();

 return 0;


}
