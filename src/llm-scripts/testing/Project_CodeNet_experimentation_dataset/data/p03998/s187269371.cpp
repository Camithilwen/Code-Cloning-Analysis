#include<bits/stdc++.h>
using namespace std;
queue<char>a,b,c;
int main(){
 string al , bo ,chr ;
 cin >> al ;
 cin >> bo ;
 cin >> chr ;
 for(int i=0;i<al.size();i++){
    a.push(al[i]);
 }
 for(int i=0;i<bo.size();i++){
    b.push(bo[i]);
 }
 for(int i=0;i<chr.size();i++){
    c.push(chr[i]);
 }
 char curr = a.front();
 a.pop();
 while(true){
     if(curr=='a'){
        if(a.empty()){
          cout << "A" <<endl;
          return 0;
        }
        curr = a.front();
        a.pop();
     }
     else if(curr=='b'){
        if(b.empty()){
          cout << "B" <<endl;
          return 0;
        }
        curr=b.front();
        b.pop();
     }
     else if(curr=='c'){
        if(c.empty()){
          cout << "C" <<endl;
          return 0;
        }
        curr=c.front();
        c.pop();
     }
 }

 return  0;
}
