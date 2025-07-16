#include<iostream>
using namespace std;

int main(){
  int n;
  char c;
  int f;

  cin >> n;
  getchar();

  f = 0;
  while(n){
    c = getchar();
    
    if(f == 1){
      if(c == 'o')f++;
      else f = 0;
    }else if(f == 2){
      if(c == 's')f++;
      else f = 0;
    }else if(f == 3){
      if(c == 'h')f++;
      else f = 0;
    }else if(f == 4){
      if(c == 'i')f++;
      else f = 0;
    }else if(f == 5){
      if(c == 'n')f++;
      else f = 0;
    }else if(f == 6){
      if(c == 'o'){
	putchar('a');
	f++;
      }else f = 0;
    }

    if(c == 'H')f = 1;

    if(c == '\n')n--;

    if(f==7)f = 0;
    else putchar(c);
  }
}