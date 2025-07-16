#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef vector <int> vi;

int main(void){
	map <char, int> m;
	vi x;
	int num[] = {1,5,10,50,100,500,1000};
	for (int i=0; i<7; i++)
		m["IVXLCDM"[i]] = num[i];

	while (true){
		string roman;
		cin>>roman;
		if (cin.eof()) break;

		int tmp, tmp2= m[roman[0]];
		for (int i=0; i<(int)roman.size(); i++){
			tmp = m[roman[i]];
			if (i!=0 && tmp2<tmp)
				x[i-1] = -tmp2;
			x.push_back(tmp);
			tmp2 = tmp;
		}

		int s=0;
		for (int i=0; i<(int)x.size(); i++)
			s += x[i];
		cout<<s<<endl;
		x.clear();
	}
}