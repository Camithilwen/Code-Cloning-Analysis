#include <bits/stdc++.h>
using namespace std;
int N; string s, a, b, A, B;
void change(int i){
  int j=(N+i-1)%N, k=(i+1)%N;
  A[i]=(A[i]=='S')?'W':'S'; a[i]=(a[i]=='o')?'x':'o';
  a[j]=(a[j]=='o')?'x':'o'; a[k]=(a[k]=='o')?'x':'o';
  B[i]=(B[i]=='S')?'W':'S'; b[i]=(b[i]=='o')?'x':'o';
  b[j]=(b[j]=='o')?'x':'o'; b[k]=(b[k]=='o')?'x':'o';
}
void flipA(int c){ for(int i=c+2; i<c+N; i+=3){change(i%N);} }
void flipB(int c){ for(int i=c+1; i<c+N; i+=3){change(i%N);} }
int main(){
cin >> N >> s;
a=string(N,'o'); b=string(N,'x');
A=string(N,'S'); B=string(N,'W');
for(int i=0; i<N-2; i++){ if(a[i]!=s[i]){change(i+1);} }  
if(a[N-2]==s[N-2]&&a[N-1]==s[N-1]){ cout << A << "\n"; }
else if(N%3==0){ cout << -1 << "\n"; }
else if(N%3==1){
  if(a[N-2]==s[N-2]){ flipA(N-1); cout << B << "\n"; }
  else if(a[N-1]==s[N-1]){ flipA(N-2); cout << B << "\n"; }
  else{ flipA(N-2); flipA(N-1); cout << A << "\n"; }
}
else{
  if(a[N-2]==s[N-2]){ flipB(N-1); cout << B << "\n"; }
  else if(a[N-1]==s[N-1]){ flipB(N-2); cout << B << "\n"; }
  else{ flipB(N-2); flipB(N-1); cout << A << "\n"; }
}
}