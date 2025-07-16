#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
int m,d;
while(scanf("%d %d",&m,&d),(m!=0)){
for(int i=0;i<m;i++){
d=d+month[i];
}
d=d%7;
switch(d){
case 0:
cout<<"Wednesday"<<endl;
break;
case 1:
cout<<"Thursday"<<endl;
break;
case 2:
cout<<"Friday"<<endl;
break;
case 3:
cout<<"Saturday"<<endl;
break;
case 4:
cout<<"Sunday"<<endl;
break;
case 5:
cout<<"Monday"<<endl;
break;
case 6:
cout<<"Tuesday"<<endl;
}
}
return 0;
}