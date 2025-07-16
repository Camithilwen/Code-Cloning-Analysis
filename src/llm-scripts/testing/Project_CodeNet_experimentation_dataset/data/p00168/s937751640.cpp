#include <iostream>
using namespace std;
int n , now = 0;
int saiki(int now){
	if( now == n )
		return 1;
	if( now > n )
		return 0;
	int res = 0;
	res += saiki(now+1)+saiki(now+2)+saiki(now+3);
	return res;
}
int main(){
	while(1){
		int x=0;
		cin >> n;
		if( n==0 ) break;
		int count = saiki(0);
		int co = count / 10;
		if( count%10 > 0 )
			co ++;
		x = co / 365 ;
		if(co%365>0)
			x ++;
		cout << x << endl;
	}
}