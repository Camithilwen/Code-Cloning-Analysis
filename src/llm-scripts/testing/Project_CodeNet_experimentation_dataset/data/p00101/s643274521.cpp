#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	string find_str("Hoshino"),rep_str("Hoshina"),target;
	int n;

	cin >> n;
	getchar();

	for( int i = 0;i < n;i++ ){
		getline(cin,target);
		for( string::size_type pos = target.find( find_str ); pos != string::npos; pos = target.find( find_str, rep_str.size() + pos ) ){
			target.replace( pos, find_str.size(), rep_str ); 
		}
		cout << target << endl;
	}
	return 0;
}