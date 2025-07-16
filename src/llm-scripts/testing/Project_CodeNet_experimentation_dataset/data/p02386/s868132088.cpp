#include<iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;

void roll(int target[], int idx[], int size,  bool rev){
  if(!rev){
    int tmp = target[idx[0]];
    for(int i=0;i<size-1;i++){
      target[idx[i]] = target[idx[i+1]];
    }
    target[idx[size-1]] = tmp;
  }else{
    int tmp = target[idx[size-1]];
    for(int i=size-1;i>0;i--){
      target[idx[i]] = target[idx[i-1]];
    }
    target[idx[0]] = tmp;
  }
}

bool is_match(int x[],int y[],int size){
  for(int i=1;i<size;i++){
    if(x[i] != y[i]) return false;
  }
  return true;
}

void pri(int x[], int size){
  for(int i=1;i<size;i++){
    cout << x[i] << " "; 
  }
  cout << endl;
}

int main(){


  static int n = 0;
  cin >> n;

  int x[n][7];

  for(int i=0;i<n;i++){
    for(int j=1;j<7;j++)
      cin >> x[i][j];
  }

  int roll_n[] = {5,1,2,6};
  int roll_e[] = {3,1,4,6};
  int roll_side[] = {3,5,4,2};

  int size = sizeof(x[0])/sizeof(int);
  int size_roll = sizeof(roll_n)/sizeof(int);

  for(int k=0;k<n;k++){
    for(int l=k+1;l<n;l++){

      for(int i=0;i<4;i++){
        roll(x[k], roll_n,size_roll,false);
        ///pri(x,size);
        for(int j=0;j<4;j++){
          roll(x[k], roll_side,size_roll,false);
          if(is_match(x[k],x[l],size)){
            cout << "No" << endl;
            return 0;
          }
        }
      }

      for(int i=0;i<4;i++){
        roll(x[k], roll_e,size_roll, false);
        for(int j=0;j<4;j++){
          roll(x[k], roll_side,size_roll, false);
          if(is_match(x[k],x[l],size)){
            cout << "No" << endl;
            return 0;
          }
        }
      }

    }
  }



  cout << "Yes" << endl;
}



