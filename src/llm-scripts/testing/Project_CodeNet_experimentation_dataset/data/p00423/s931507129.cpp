#include<iostream>
using namespace std;

int main(){
int n = 1;
while(1){
 cin >> n;
if (n == 0){
break;
}
int apoint = 0;int bpoint = 0;
int i = 1;
for(i = 1;i <= n;i++){
int a = 0;int b = 0;
cin >> a >> b;
if(a == b){
apoint = apoint + a;
bpoint = bpoint + b;
}
else if(a > b){
apoint = apoint + a + b;
}
else{
bpoint = bpoint + a + b;
}
} 
cout << apoint << " " << bpoint << endl;
}
    return 0;
}