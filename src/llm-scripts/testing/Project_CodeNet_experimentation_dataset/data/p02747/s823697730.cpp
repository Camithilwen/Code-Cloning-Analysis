#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#include <iomanip>
#define rep(i,N) for(ll i=0;i<N;i++)
#define disp(a) cout << a << endl;
#define PI 3.1415926535897932384626433
//cout << fixed << setprecision(20) << ** << endl;
typedef long long ll;
using namespace std;

double deg2rad(double degree)
{
    return degree * PI / 180.0000000000;
}
int main()
{
	string s,ANS="Yes";
	cin>>s;
	if(s.size()%2!=0){
		cout<<"No"<<endl;
	}
	else{
		for(int i=0;i<s.size();i=i+2){
			if(s[i]=='h'&&s[i+1]=='i'){
				continue;
			}
			else{
				ANS="No";
			}
		}
		cout<<ANS<<endl;
	}

}