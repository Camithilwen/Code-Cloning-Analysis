#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
 
int main () {
	int n,m,i,j,t=0;
	int a,b,c,d,f,g,a11,b1,c1,d1,f1,g1;
	string s="EEEESEEEESEEEESEEEESESEEEESSEEE";
	n=s.size();
	int a1[n+1],a2[n+1],a3[n+1],a4[n+1],a5[n+1],a6[n+1];
	cin >> m;
	cin >> a >> b >> c >> d >> f >> g ;
	for(j=0;j<m-1;j++){
		int a1[n+1],a2[n+1],a3[n+1],a4[n+1],a5[n+1],a6[n+1];
		cin >> a11 >> b1 >> c1 >> d1 >> f1 >> g1;
		a1[0]=a11; a2[0]=b1; a3[0]=c1; a4[0]=d1; a5[0]=f1; a6[0]=g1;
		for(i=0;i<n;i++){
			if(s[i]=='S'){
				a1[i+1]=a5[i]; a2[i+1]=a1[i]; a3[i+1]=a3[i]; a4[i+1]=a4[i]; a5[i+1]=a6[i]; a6[i+1]=a2[i];
			}	
			else if(s[i]=='N'){
				a1[i+1]=a2[i]; a2[i+1]=a6[i]; a3[i+1]=a3[i]; a4[i+1]=a4[i]; a5[i+1]=a1[i]; a6[i+1]=a5[i];
			}
			else if(s[i]=='W'){
				a1[i+1]=a3[i]; a2[i+1]=a2[i]; a3[i+1]=a6[i]; a4[i+1]=a1[i]; a5[i+1]=a5[i]; a6[i+1]=a4[i];
			}
			else if(s[i]=='E'){
				a1[i+1]=a4[i]; a2[i+1]=a2[i]; a3[i+1]=a1[i]; a4[i+1]=a6[i]; a5[i+1]=a5[i]; a6[i+1]=a3[i];
			}
			if((a1[i+1]==a)&&(a2[i+1]==b)&&(a3[i+1]==c)&&(a4[i+1]==d)&&(a5[i+1]==f)&&(a6[i+1]==g)){
				t=1;  break;
			}
		}
	}
	if(t==1) cout << "No" << endl;
	else cout << "Yes" << endl;
}