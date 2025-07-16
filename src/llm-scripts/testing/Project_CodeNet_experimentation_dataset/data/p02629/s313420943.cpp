#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  
void func(long long x){
  if(x==0){
    cout<<"a";
  }
  else if(x==1){
    cout<<"b";
  }
  else if(x==2){
    cout<<"c";
  }
  else if(x==3){
    cout<<"d";
  }
  else if(x==4){
    cout<<"e";
  }
  else if(x==5){
    cout<<"f";
  }
  else if(x==6){
    cout<<"g";
  }
  else if(x==7){
    cout<<"h";
  }
  else if(x==8){
    cout<<"i";
  }
  else if(x==9){
    cout<<"j";
  }
  else if(x==10){
    cout<<"k";
  }
  else if(x==11){
    cout<<"l";
  }
  else if(x==12){
    cout<<"m";
  }
  else if(x==13){
    cout<<"n";
  }
  else if(x==14){
    cout<<"o";
  }
  else if(x==15){
    cout<<"p";
  }
  else if(x==16){
    cout<<"q";
  }
  else if(x==17){
    cout<<"r";
  }
  else if(x==18){
    cout<<"s";
  }
  else if(x==19){
    cout<<"t";
  }
  else if(x==20){
    cout<<"u";
  }
  else if(x==21){
    cout<<"v";
  }
  else if(x==22){
    cout<<"w";
  }
  else if(x==23){
    cout<<"x";
  }
  else if(x==24){
    cout<<"y";
  }
  else{
    cout<<"z";
  }
}

int main(void){
  long long  i,j;
  long long tmp=0;
  long long res;
  long k;
  cin>>k;
  long long base[13];
  long long order[13];
  
  base[0]=1;
  order[0]=0;
  
  for(i=1;i<13;i++){
    base[i]=pow(26,i);
    order[i]=order[i-1]+base[i];
    if(k<order[i]){
      break;  
    }
    else if(k==order[i]){
      for(;i>0;i--){
        cout<<"z";
      }
      cout<<endl;
      return 0;
    }
  }
  
  tmp=k-order[i-1]-1;
  
  for(i=i-1;i>=0;i--){
    res=tmp/base[i];
    if(i==0){
      func(res);
    }
    else{
      func(res);
    }
    tmp=tmp%base[i];
  }   

  cout<<endl;
  return 0;
}