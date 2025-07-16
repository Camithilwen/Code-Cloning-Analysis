#include<iostream>
#include<vector>
using namespace std;

int main(){
   string s;
   cin >> s;
   
   for(int i=0;i<s.size();i++){
       if(s[i]=='h'){
           if(s[i+1]=='i'){
               i++;
           }else{
               cout << "No" << endl;
           return 0;
           }
       }else{
           cout << "No" << endl;
           return 0;
       }
   }
   cout << "Yes" << endl;
}