#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int main(){
  char str[1000], cmd[7], p[1000];
  int a, b, q;
  string OUT;
  scanf("%s", str);
  string STR = str;
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%s %d %d", cmd, &a, &b);
    string CMD = cmd;
    if(CMD == "replace"){
      scanf("%s", p);
      string P = p;
      STR.replace(a, b - a + 1, P);
    }
    else if(CMD == "reverse"){
      string R;
      for(int j = b; j >= a; j--){
	R += STR[j];
      }
      STR.replace(a, b - a + 1, R);
    }
    else if(CMD == "print"){
      for(int k = a; k <= b; k++){
	OUT += STR[k];
      }
      OUT += "\n";
    }
  }
  char* out;
  out = (char*)malloc(OUT.length() + 1);
  sprintf(out, "%s", OUT.c_str());
  printf("%s", out);
  free(out);
  return 0;
}