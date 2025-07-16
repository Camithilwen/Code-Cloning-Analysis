/*
 * src.cpp
 *
 *  Created on: 2016/08/04
 *      Author: joi
 */

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

const int MAX_N=1e4;

int n;
int p[3];

char out[MAX_N+5];

int main(){
	do{
		cin>>n;
		if (n){
			REP(i,n){
				int ave=0;
				bool f=false;
				REP(j,3){
					cin>>p[j];
					ave+=p[j];
					if (p[j]==100){
						f=true;
					}
				}
				if (f){
					out[i]='A';
				}else if (p[0]+p[1]>=180){
					out[i]='A';
				}else if (ave>=80*3){
					out[i]='A';
				}else if (ave>=70*3){
					out[i]='B';
				}else if (ave>=50*3 && (p[0]>=80 || p[1]>=80)){
					out[i]='B';
				}else{
					out[i]='C';
				}
			}
			REP(i,n){
				cout<<out[i]<<endl;
			}
		}
	}while (n);
	return 0;
}