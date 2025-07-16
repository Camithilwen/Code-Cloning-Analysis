#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m; 
	cin >> n >> m; 
	
	int a[n + 2]; 
	memset(a, 0, sizeof a); 
	
	for (int i = 0; i < m ; i++)
	{
		int x, y; 
		cin >> x >> y; 
		
		a[x]++; 
		a[y + 1] --; 
		
	}
	
	for(int i = 1; i <= n; ++i){
		  a[i] += a[i-1]; 
	  }
		
	 int count = 0; 
	for(int i = 1; i <= n; ++i){
		if(a[i] == m){
			count++; 
		}
	}
	
	cout << count << endl; 
}
	
	
	
