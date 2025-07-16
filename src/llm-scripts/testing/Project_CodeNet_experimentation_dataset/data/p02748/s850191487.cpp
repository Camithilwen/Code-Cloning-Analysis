#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,M;
    cin >> A>>B>>M;
    vector<int>veca(A);
    vector<int>vecb(B);
    for(int i=0;i<A;i++){
        cin>>veca.at(i);
    }
    for(int i=0;i<B;i++){
        cin>>vecb.at(i);
    }
    int countera=999999;
    int counterb=999999;
    for(int i=0;i<A;i++){
   countera=min(countera,veca.at(i));
    }
    for(int i=0;i<B;i++){
   counterb=min(counterb,vecb.at(i));
    }
    int counter=countera+counterb;
    vector<vector<int>>vec(M,vector<int>(3));
   for(int i=0;i<M;i++){
    for(int j=0;j<3;j++){
        cin >> vec.at(i).at(j);
    }
   }
      for(int i=0;i<M;i++){
     counter= min(veca.at(vec.at(i).at(0)-1)+vecb.at(vec.at(i).at(1)-1)-vec.at(i).at(2),counter);
    }
    cout <<counter <<endl;
   }
   