#include<iostream>
#include<string>

signed main() {
  int h,w,a,b;
    scanf("%d%d%d%d",&h,&w,&a,&b);
    	std::string s(a,'0');
    	std::string t(w-a,'1');
        std::string ans=s+t;
  		std::string S(a,'1');
  		std::string T(w-a,'0');
  		std::string Ans=S+T;
  for(int i=0;i<h;++i){
    if(i<b){
    	printf("%s\n",ans.c_str());
    }
    else{
    	printf("%s\n",Ans.c_str());
    }
  }
}