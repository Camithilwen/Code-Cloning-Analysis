#include <iostream>

using namespace std;
int main(){
	int d;
	cin>>d;
	string buf;
	string key="Hoshino";
	string newkey="Hoshina";
	unsigned int p;
getline(cin,buf);
	while(d--){
		getline(cin,buf);
		while((p=buf.find(key,0))!=string::npos){
			buf.replace(p,key.size(),newkey);
		}
		cout<<buf<<endl;
	}
	return 0;
}