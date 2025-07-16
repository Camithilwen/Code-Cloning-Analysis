#include<bits/stdc++.h>
using namespace std;

int main(){
	string sa;
	
	while(getline(cin,sa)){
		
		for(int j=0;j<26;j++){
			int a=sa.size();
		for(int i=0;i<a;i++){
			if(sa[i]>='a'&&sa[i]<='z'){
				sa[i]+=1;
				if(sa[i]>'z'){
					sa[i]-=26;
					}
				}
			}	
			size_t z=sa.find("this");
			size_t za=sa.find("that");
			size_t zb=sa.find("the");
			if(z!=string::npos){break;}
			else if(za!=string::npos){break;}
			else if(zb!=string::npos){break;}
			}
			cout<<sa<<endl;
			
		}
		return 0;
	}