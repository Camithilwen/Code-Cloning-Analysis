
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define INF 1000000001
#define MOD 1000000007

using namespace std;



class Dice {
public:
	int num[6] = { 0,0,0,0,0,0 };
	void setnum(int*);
	void roll(char);
	void dice3(Dice, Dice);
};

void Dice::roll(char c) {
	switch
 (c) {
		int tmp;
	case'N':
		tmp = num[0];
		num[0] = num[1];
		num[1] = num[5];
		num[5] = num[4];
		num[4] = tmp;
		break;
	case'S':
		tmp = num[0];
		num[0] = num[4];
		num[4] = num[5];
		num[5] = num[1];
		num[1] = tmp;
		break;
	case'E':
		tmp = num[0];
		num[0] = num[3];
		num[3] = num[5];
		num[5] = num[2];
		num[2] = tmp;
		break;
	case'W':
		tmp = num[0];
		num[0] = num[2];
		num[2] = num[5];
		num[5] = num[3];
		num[3] = tmp;
		break;
	default:
		cout << "invalid char" << endl;
	}
}

void Dice::setnum(int* a) {
	REP(i, 6) {
		num[i] = a[i];
	}
}

bool isSame(Dice d1, Dice d2) {
	int flag = 1;
	REP(i, 6) {
		if (d1.num[i] != d2.num[i]) {
			flag = 0;
		}
	}
	if (flag) return true;
	else return false;
}

bool dice4(Dice d1, Dice d2) {
	int flag0 = 0;
	int a  = d1.num[0];
	REP(i, 6) {
		if (a == d2.num[i]) {
			flag0 = 1;
		}
	}
	if (flag0) {
		REP(i, 3) {
			REP(j, 4) {
				if (isSame(d1, d2)) {
					return true;
				}
				d1.roll('E');
				d1.roll('N');
				d1.roll('W');
			}
			d1.roll('E');
			REP(j, 4) {
				if (isSame(d1, d2)) {
					return true;
				}
				d1.roll('E');
				d1.roll('N');
				d1.roll('W');
			}
			d1.roll('N');
		}
	}
	return false;
}




int main() {
	int n,flag=0;
	cin >> n;
	vector<Dice> dice;
	REP(i, n) {
		Dice d;
		dice.push_back(d);
		int tmp[6];
		REP(j, 6){ 
			int c;
			cin >> c;
			tmp[j]=c;
		}
		dice[i].setnum(tmp);
	}
	REP(i, n) {
		FOR(j, i+1, n) {
			if (dice4(dice[i], dice[j]))flag = 1;
		}
	}
	if (flag)cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}