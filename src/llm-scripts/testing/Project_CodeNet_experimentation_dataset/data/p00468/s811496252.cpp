#include <bits/stdc++.h>
#define fo(i,a) for(i = 0;i < a;i++)
using namespace std;
int main(void)
{
	int n,m,fr=0,i,a[10001],b[10001],flag[10001]={0};
	flag[0] = 1;
	
	cin >> n >> m ;
	while(n != 0 || m != 0){
		fo(i,m){
			cin >> a[i] >> b[i] ;
			if(a[i] == 1){
				fr++ ;
				flag[b[i]] = 2 ;
			}
		}
		fo(i,m){
			if(flag[a[i]] == 2 && flag[b[i]] == 0){
				fr++ ;
				flag[b[i]] = 3 ;
			}
		}
		fo(i,m){
			if(flag[a[i]] == 0 && flag[b[i]] == 2){
				fr++ ;
				flag[a[i]] = 3 ;
			}
		}
		cout << fr-1 << endl;
		fr = 0;
		flag[0] = 1 ;
		fill (flag,flag + 10001,0);
		cin >> n >> m ;
	}
	
	return 0;
}