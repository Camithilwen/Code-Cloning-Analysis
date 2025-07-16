#include<iostream>
#include<algorithm>
using namespace std;

struct CROPS{
  string name;
  double total;

};

int main(){
  int i,j,n;
  double p,a,b,c,d,e,f,s,m,efficient;
  CROPS crop[51];
   while(1){
    cin >> n;
     if(n==0)break;
    for(i = 0; i < n; i++){
      cin >> crop[i].name >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      efficient=(f*s*m-p)/(a+b+c+(d+e)*m);
      crop[i].total=efficient;
    }
      
    for(i = 0; i < n; i++){
      for(j = 0; j < n-1; j++){
	if(crop[j].total < crop[j+1].total){
	  swap(crop[j],crop[j+1]);
	}
      }
    }

    for(i = 0; i < n; i++){
      for(j = 0; j < n-1; j++){
	if(crop[j].total == crop[j+1].total && crop[j].name>crop[j+1].name){
	  swap(crop[j],crop[j+1]);
	}
      }
    }
  
    for(i = 0; i < n; i++){
      cout << crop[i].name << endl;      
    }

    cout << "#" << endl;
     }
  return 0;
}