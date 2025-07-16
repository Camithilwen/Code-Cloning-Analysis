#include<iostream>
#include<vector>
using namespace std;

long long N,ans;
string S;
string S1,S2;
vector <string> V1,V2;

string convstr(string str,long long key){
  string f="";string l="";
  for (long long i=0;i<N;i++){
    if ((key&(1<<i))!=0){
      f=f+str[i];
    } else l=str[i]+l;
  }
  return f+" "+l;
}

int main(){
  cin >> N >> S;
  S1="";S2="";
  for (long long i=0;i<N;i++){
    S1=S1+S[i];
    S2=S2+S[2*N-1-i];
  }

  for (long long i=0;i<(1<<N);i++){
    V1.push_back(convstr(S1,i));
  }
  sort(&V1[0],&V1[1<<N]);
  /*
  for (int i=0;i<V1.size();i++){
    cout << V1[i] << endl;
  }
  */
  for (long long i=0;i<(1<<N);i++){
    V2.push_back(convstr(S2,i));
  }
  sort(&V2[0],&V2[1<<N]);
  /*
  for (int i=0;i<V2.size();i++){
    cout << V2[i] << endl;
  }
  */
  long long idx1=0,idx2=0;
  long long mul1=0,mul2=0;
  ans=0;
  while(idx1<(1<<N) && idx2<(1<<N)){
    if (V1[idx1]>V2[idx2]){
      idx2++;continue;
    }
    if (V1[idx1]<V2[idx2]){
      idx1++;continue;
    }


    mul1=0;mul2=0;
    while(idx1+mul1<(1<<N) && V1[idx1]==V1[idx1+mul1]){
      mul1++;
    }
    while(idx2+mul2<(1<<N) && V2[idx2]==V2[idx2+mul2]){
      mul2++;
    }
    ans+=mul1*mul2;
    //cout << V1[idx1] << " " << V2[idx2]<<" " << mul1*mul2 <<endl;
    idx1+=mul1;idx2+=mul2;
  }
  cout << ans << endl;
}
