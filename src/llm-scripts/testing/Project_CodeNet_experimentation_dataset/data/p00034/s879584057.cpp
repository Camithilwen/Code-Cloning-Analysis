#include <iostream>
#include <string>
using namespace std;

int main()
{
	int l[10], v1, v2, cnt;
	double n, d, t;
	char ch;
	while (cin>>l[0]>>ch){
		n = l[0];
		for (int i = 1; i < 10; i++)
		{
		    cin >> l[i] >> ch;
		    n += l[i];
		}
		cin >> v1 >> ch >> v2;
		t=n/(v1+v2);
		d=v1*t;    //列車1の動く距離
		cnt=0;
		while(d>0){
			d -= l[cnt];
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}