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

int N;

int cnt[10];

int main(){
	do{
		cin>>N;
		if (N){
			fill(cnt,cnt+10,0);
			REP(i,N){
				int a;
				cin>>a;
				cnt[a]++;
			}
			REP(i,10){
				if (cnt[i]==0){
					cout<<'-'<<endl;
				}else{
					REP(j,cnt[i]){
						cout<<'*';
					}
					cout<<endl;
				}
			}
		}
	}while (N);
	return 0;
}