#include<bits/stdc++.h>

using namespace std;

int main() {
int H,W;
cin>>H>>W;
char s[60][60];
int a=0;
for(int i=1;i<=H;i++){
   for(int j=1;j<=W;j++){
      cin>>s[i][j];
   }
}
for(int i=1;i<=H;i++){
   for(int j=1;j<=W;j++){
      if(s[i][j]=='#'&&s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#'){
         a++;
      }
   }
}
if(a==0){
   cout<<"Yes"<<endl;
}
else{
   cout<<"No"<<endl;
}


   return 0;
}




