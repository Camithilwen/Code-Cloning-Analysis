#include <iostream>
using namespace std;

char a[1000001];
char w[] = "JOI";
int k=0, l[3];

int main() {
  
  cin>>a;
  
  for(char* c=a;*c!='\0';) {
    for(int i=0;i<3;++i) {
      l[i]=0;
      while(*c!='\0'&&*c==w[i]) {
        ++l[i];
        ++c;
      }
    }
    if(l[0]>=l[1]&&l[2]>=l[1])k=(k<l[1]?l[1]:k);
  }
  
  cout<<k<<endl;
  
  return 0;
}