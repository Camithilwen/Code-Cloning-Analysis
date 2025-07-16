#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const char ok = '1';
const char no = '0';

struct P{
	int x;
	int y;
	int z;
};

int main()
{
	int a, b, c, n, v;
	char ch[301];
	P p;
	
	while(cin>>a>>b>>c && (a+b+c)){
		cin >> n;
		fill(ch, ch+301, '2');
		vector<P> vec;
		
		while(n--){
			cin >> p.x >> p.y >> p.z >> v;
			if(v == 1){
				ch[p.x] = ch[p.y] = ch[p.z] = ok;
			} else {
				vec.push_back(p);
			}
		}
		
		for(int i = 0; i < vec.size(); i++){
			if(ch[vec[i].x] == ok && ch[vec[i].y] == ok){
				ch[vec[i].z] = no;
			} else if(ch[vec[i].x] == ok && ch[vec[i].z] == ok){
				ch[vec[i].y] = no;
			} else if(ch[vec[i].y] == ok && ch[vec[i].z] == ok){
				ch[vec[i].x] = no;
			}
		}
		for(int i = 1; i <= a+b+c; i++){
			cout << ch[i] << endl;
		}
	}
	
	return 0;
}