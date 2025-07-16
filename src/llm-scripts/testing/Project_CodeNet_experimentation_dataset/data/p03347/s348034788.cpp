#include <iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long answer=0;
  long long before=-1;
  int judge=0;
  for(int i=0;i<N;i++){
    long long A;
    cin>>A;
    if(A>before+1){
      cout<<-1<<endl;
      judge++;
      break;
    }
    else if(A<=before) answer+=before;
    if(i==N-1) answer+=A;
    before=A;
  }
  if(judge==0) cout<<answer<<endl;
  
  
  return 0;
}