#include <iostream>
#include <string>
using namespace std;
int main(){
	string a;
	while(getline(cin,a)){
	int k=0;
	int check=0;
	while(true){
		if(k>52)
			break;
		for(int j=0;j<a.size();j++){
			if(isalpha(a[j])!=0)
				if(a[j]=='z')
					a[j]='a';
				else
				    a[j]++;
		}
		for(int i=0;i<a.size()-2;i++){
			if(a[i]=='t'&&a[i+1]=='h'&&a[i+2]=='e'&&check==0){
				for(int i=0;i<a.size();i++)
		            cout<<a[i];
	            cout<<endl;
				check=1;
			}
			if(a[i]=='t'&&a[i+1]=='h'&&a[i+2]=='i'&&a[i+3]=='s'&&check==0){
				for(int i=0;i<a.size();i++)
		            cout<<a[i];
	            cout<<endl;
				check=1;
			}
			if(a[i]=='t'&&a[i+1]=='h'&&a[i+2]=='a'&&a[i+3]=='t'&&check==0){
				for(int i=0;i<a.size();i++)
		            cout<<a[i];
	            cout<<endl;
				check=1;
			}
		}
		k++;
	}
	}
	return 0;
}