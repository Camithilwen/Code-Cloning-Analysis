#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,a,b,c=0;
  string s1[3],s2[1];
  char str1[11];
  cin >> s1[0] >> n;
 
  for(int i=0;i<n;i++){
    cin >> s1[1] >> a >> b;

    if(s1[1] == "replace"){      // 置き換え
      cin >> s2[0];
      for(int j=a;j<=b;j++){
	s1[0][j]=s2[0][c];
	c++;
      }
      c=0;
    }

    if(s1[1] == "reverse"){      // 逆順
      for(int j=0;j<=(b-a)/2;j++){
	str1[0]=s1[0][a+j];
	s1[0][a+j]=s1[0][b-j];
	s1[0][b-j]=str1[0];
      }
    }

    if(s1[1] == "print"){        // 出力
      for(int j=a;j<=b;j++){
	cout << s1[0][j];
      }
      cout << endl;
    }

  }

  return 0;
}