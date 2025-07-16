#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    long double dx,dy,RR,avdist,prt;
    cin >>N;
    int arrive[N];
    vector<vector<long double>> b(N, vector<long double>(2));
    vector<vector<long double>> dist(N, vector<long double>(N,0));
    for(int i=0;i<N;i++){
      arrive[i]=i;
      cin >> b.at(i).at(0) >> b.at(i).at(1);
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        dx=b.at(i).at(0)-b.at(j).at(0);
        dy=b.at(i).at(1)-b.at(j).at(1);
        RR=pow(pow(dx,2)+pow(dy,2),0.5);
        dist.at(i).at(j)= RR;
        //cout << RR << endl;
    	}
    } 
  avdist=0;
  prt=0;
   do{
    for(int k=0;k<N-1;k++){
     avdist+=dist.at(arrive[k]).at(arrive[k+1]);
     }
         prt+=1;
     }while(next_permutation(arrive, arrive + N));
       cout << fixed << setprecision(10) << avdist/prt << endl;
   return 0;
     
    
}