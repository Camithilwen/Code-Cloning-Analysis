#include <map>
#include <iostream>

using namespace std;

/** Problem0039 : Roman Figure **/
int main()
{
	char num[110]; int now, old, ans;
	map<char, int> list;
	list.insert(map<char, int>::value_type('I', 1));
	list.insert(map<char, int>::value_type('V', 5));
	list.insert(map<char, int>::value_type('X', 10));
	list.insert(map<char, int>::value_type('L', 50));
	list.insert(map<char, int>::value_type('C', 100));
	list.insert(map<char, int>::value_type('D', 500));
	list.insert(map<char, int>::value_type('M', 1000));
	
	while (cin >> num) {
		ans = 0;
		old = list[num[0]];
		for (int i=1; i<110 && num[i]!='\0'; i++) {
			now = list[num[i]];
			if (old == 0) {
				old = now;
			} else if (old<now) {
				ans += (now-old);
				old = 0;
			} else {
				ans += old;
				old = now;
			}
		}
		ans += old;
		cout << ans << endl;
	}
	
	return 0;
}