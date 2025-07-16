#include<iostream>
using namespace std;

class Dice {
    public:
	int f[7];
	Dice() {}
	void roll_x() { roll(1, 4, 6, 3); } // to E
	void roll_y() { roll(1, 2, 6, 5); } // to N
	void roll_z() { roll(2, 3, 5, 4); } // 上から見て時計回り
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
};

bool judge(Dice c1, Dice c2) {
	for (int i = 1; i <= 6; i++) {
		if (c1.f[i] != c2.f[i]) return false;
	}
	return true;
}


bool getRight(Dice c1, Dice c2) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (judge(c1, c2)) return true;
			c1.roll_z();
		}
		if (i % 2 == 0) c1.roll_x();
		else c1.roll_y();
	}
	return false;
}

Dice D[100]; int n;

bool check(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(getRight(D[i],D[j])) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=6;j++){
            cin >> D[i].f[j];
        }
    }

	if(check()) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}


