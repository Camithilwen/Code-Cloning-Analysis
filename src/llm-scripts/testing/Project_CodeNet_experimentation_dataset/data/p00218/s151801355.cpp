#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  struct test{
    int Math;
    int English;
    int Japanese;
  };

  int n;
  double total;
  test student;

  while(1){
    total=0;
    cin >> n;
    if(n==0)break;

    for(int i=0;i<n;i++){
      char rank='A';
      while(1){
	cin >> student.Math >> student.English >> student.Japanese;
	if(student.Math==100||student.English==100||student.Japanese==100)break;
	total=student.Math+student.English;
	total=total/2;
	if(total>=90)break;
	total=student.Math+student.English+student.Japanese;
	total=total/3;
	if(total>=80)break;
	
	rank='B';
	if(total>=70){
	  break;
	}
	if(total>=50&&(student.Math>=80||student.English>=80))break;
	
	rank='C';
	if(1)break;
      }
      cout << rank << endl;
    }
  }
  return 0;
}