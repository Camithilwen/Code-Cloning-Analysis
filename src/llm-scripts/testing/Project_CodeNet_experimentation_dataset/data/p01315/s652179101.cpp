#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define double long double
typedef pair<double, string> P;

bool solve(){
	int n;
	string name;
	int p, a, b, c, d, e, f, s, m;
	P data[50];
	
	cin >> n;
	if( n == 0 ) return false;
	for( int i = 0; i < n; i++ ){
		cin >> name >> p >> a >> b >> c >> d >> e >> f >> s >> m;
		int income = s * f * m - p;
		int timer = a + b + c + m * (d + e);
		double effect = (double)income / timer;
		data[i].first = -effect;	//Swap Order Technic.
		data[i].second = name;
	}
	sort(data, data + n);
	
	for( int i = 0; i < n; i++ ){
		cout << data[i].second << endl;
	}
}

int main(){
	while(1){
		if( !solve() )
			break;
		else
			cout << "#" << endl;
	}
	return 0;
}