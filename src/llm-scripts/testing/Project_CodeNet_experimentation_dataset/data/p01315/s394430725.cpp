#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#define MAX 50
using namespace std;

typedef struct {
  string name;
  double rate;
}hurvest;

bool cmp(const hurvest &a,const hurvest &b){
  return a.rate > b.rate;
}

int main(){
  array<hurvest,MAX> data;
  int n,seed_cost,time_sum,time,value,F,S,M,D,E;

  while(1){
  cin >> n;
  if(n==0){
    break;
  }
  for(int i=0;i<n;i++){
    cin >> data[i].name>>seed_cost;
    time_sum=0;
    for(int j=0;j<5;j++){
      cin >> time;
      if(j==3){
	D=time;
      }
      if(j==4){
	E=time;
      }
      time_sum+=time;
    }
    
    cin >> F >> S >> M;
    value=F*S;
    if(M!=1){
      value*=M;
      time_sum+=(E+D)*(M-1);
    }
    data[i].rate=(double)(value-seed_cost)/(double)time_sum;
  }

  sort(data.begin(),data.end()-(50-n),cmp);

  bool change=true;
  hurvest temp;
  while(change){
    change=false;
    for(int i=0;i<n-1;i++){
      if(data[i].rate==data[i+1].rate){
	if(data[i].name>data[i+1].name){
	  temp=data[i];
	  data[i]=data[i+1];
	  data[i+1]=temp;
	  change=true;
	}
      }
    }
  }

  for(int i=0;i<n;i++){
    cout << data[i].name<<endl;
  }
  cout << '#' <<endl;
  }


  return 0;
}

