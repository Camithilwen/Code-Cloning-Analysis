#include<iostream>
#include<stdlib.h>
using namespace std;

int main (){
  int n, m;
  int b, count, answer;
  int *list, *result;
  list = (int*)malloc(sizeof(int)*n);
  result = (int*)malloc(sizeof(int)*n);

  cin >> n >> m;
  for(int i = 0; i<n; i++){
    cin >>list[i];
    result[i] = 0;
  }

  for(int i= 0; i< m; i++){
    count = 0;
    cin >>b;
    while(1){
      if(list[count] < b+1) break;
      count++;
    }
    //cout <<count <<endl ;
    result[count] ++;
  }
  answer = 0;
  for(int i =0; i<n; i++){
    if(result[answer] < result[i])
      answer = i ;
  }

  cout << answer + 1 <<endl;
  return 0;
}
    
    
      
      
    
  
  