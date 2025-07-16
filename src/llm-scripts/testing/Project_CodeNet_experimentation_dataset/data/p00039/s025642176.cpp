#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef vector <string> vs;

int main(void){
	map <char, int> m;
	int num[] = {1,5,10,50,100,500,1000};
	for (int i=0; i<7; i++)
		m["IVXLCDM"[i]] = num[i];

	char c;
	string r;
	while (cin>>r){
		int tmp, tmp2= m[r[0]],s=0;
		int n=r.size();
		for (int i=0; i<n; i++){
			tmp = m[r[i]];
			if (tmp2<tmp)
				s-= tmp2*2;
			s += tmp;
			tmp2 = tmp;
		}
		cout<<s<<endl;
	}
}