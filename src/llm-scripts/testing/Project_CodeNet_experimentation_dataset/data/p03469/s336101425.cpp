#include <iostream>
 
 using namespace std;
  int main() {
       string s;
       while(cin>>s){
       int l=s.length();
       for(int i=0;i<l;i++){
       if(i==0) cout<<'2';
       else if(i==1) cout<<'0';
       else if(i==2) cout<<'1';
       else if(i==3) cout<<'8';
       else cout<<s[i];
                }
           cout<<endl;
		        }
    
	 return 0;
	  }