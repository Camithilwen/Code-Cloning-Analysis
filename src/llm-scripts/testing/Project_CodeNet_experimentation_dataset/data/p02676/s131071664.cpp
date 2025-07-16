#include<bits/stdc++.h>
using namespace std;
#include <string>

int main(){
	int k;
  cin>>k; 
  string palabra;
  cin>>palabra;
  int tamano;
  tamano=palabra.size();
    if (tamano>k){
          for(int i=0;i<k;i++){
          cout<<palabra[i];
          }
          cout<<"...";
      }
      else{
        cout<<palabra<<endl;
    }
      
}