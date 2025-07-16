#include<bits/stdc++.h>
using namespace std;

int N;
const double EPS = 1e-10;

struct state{
  string name;
  double k;
  state(){}
  state(int P,int A,int B,int C,int D, int E,int F,int S,int M){
    int time = A + B + C + (D + E)*M;
    int num = M * F;
    int mon = num * S;
    int s = mon - P;
    k = (double)s/(double)time;
  }
  bool operator<(const state& st) const {
    return abs(k-st.k) < EPS ? name < st.name : k > st.k;
  }
};

state st[111];
int main(){
  while( cin >> N && N ){
    for(int i=0;i<N;i++){
      string L;int P,A,B,C,D,E,F,S,M;
      cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
      st[i] = state(P,A,B,C,D,E,F,S,M);
      st[i].name = L;
   
    }
    sort(st,st+N);
    for(int i=0;i<N;i++)
      cout << st[i].name << endl;
    cout << "#" << endl;
  }
}