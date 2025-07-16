#include <vector>
#include <iostream>
#include <map>
using namespace std;
template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	map<char,int> t;
	t['I']=1, t['X']=10, t['V'] = 5;
	t['L'] = 50 , t['C'] = 100 , t['M'] = 1000 , t['D'] = 500;
	string s;
	while(cin >> s){
		int ret = 0;
		ret += t[s[0]];
		rep(i,s.length()-1){
			if(t[s[i+1]] > t[s[i]])ret -= 2*t[s[i]];
			ret += t[s[i+1]];
		}
		cout << ret << endl;
	}
}