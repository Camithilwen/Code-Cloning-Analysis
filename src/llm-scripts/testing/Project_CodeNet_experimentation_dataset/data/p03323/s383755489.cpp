#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
   int x, y;
   cin >> x >> y;
   int a[100]; memset(a,0,sizeof(a));
   bool ok = true;
   int cnt = 0;
   for(int i = 1; i <= 16; i++){
   	cnt++;
   	if(cnt > 100){
   	 	ok = false; break;
   	}
   	int prev = i-1; 
   	if(prev < 1)prev = 16;
    	if(a[i] == 0 && a[prev] != 1){
    	 	a[i] = 1;
    	 	x--; 
    	 	if(x == 0)break;
    	}
    	if(i == 16)i = 0;
   }
   cnt = 0;

   for(int i = 1; i <= 16; i++){
		cnt++;
		int prev = i-1;
		if(prev < 1)prev = 16;
		if(cnt > 100){
		 	ok = false; break;
		}
		if(a[i] == 0 && a[prev] != 2){
		 	a[i] = 2;
		 	y--;
		 	if(y == 0)break;
    	}
    	if(i == 16)i = 0;
   }
   cout << (ok ? "Yay!" : ":(") << endl;
	return 0;
}                  
