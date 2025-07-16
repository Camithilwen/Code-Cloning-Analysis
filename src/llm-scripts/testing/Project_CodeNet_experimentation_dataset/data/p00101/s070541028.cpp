#include <iostream>
#include <string>
using namespace std;

const string check = "Hoshino";

int main()
{
	int n;
	string str;
	cin >> n;
	getline(cin,str);
	for(int loop=0;loop<n;loop++){
		getline(cin,str);
		for(unsigned i=0;i<str.size();i++){
			bool flag = true;
			for(unsigned j=0;j<check.size();j++){
				if(i+j < str.size()){
					if(str[i+j] != check[j])
						flag = false;
					else{
						if(j == check.size()-1 && flag)
							str[i+j] = 'a';
					}
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}