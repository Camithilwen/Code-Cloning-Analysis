#include<string>
#include<iostream>
using namespace std;


class Dice{
	int dn[6];
	int ori[6];
	int up, front;
	string qu;

public:
	Dice(int d1, int d2, int d3, int d4, int d5, int d6){
		dn[0] = d1;
		dn[1] = d2;
		dn[2] = d3;
		dn[3] = d4;
		dn[4] = d5;
		dn[5] = d6;

		ori[0] = d1;
		ori[1] = d2;
		ori[2] = d3;
		ori[3] = d4;
		ori[4] = d5;
		ori[5] = d6;
	}

	void Result(string m){
		int w;
		qu = m;
		for (int i = 0; i < 6; i++){
			dn[i] = ori[i];
		}

		for (int i = 0; i < qu.size(); i++){
			switch (qu[i]){
			case 'E':
				w = dn[0];
				dn[0] = dn[3];
				dn[3] = dn[5];
				dn[5] = dn[2];
				dn[2] = w;
				break;

			case 'N':
				w = dn[5];
				dn[5] = dn[4];
				dn[4] = dn[0];
				dn[0] = dn[1];
				dn[1] = w;
				break;

			case 'S':
				w = dn[0];
				dn[0] = dn[4];
				dn[4] = dn[5];
				dn[5] = dn[1];
				dn[1] = w;
				break;

			case 'W':
				w = dn[0];
				dn[0] = dn[2];
				dn[2] = dn[5];
				dn[5] = dn[3];
				dn[3] = w;
				break;
			}
		}
	}

	int get0(){
		return dn[0];
	}
	int get1(){
		return dn[1];
	}
	int get2(){
		return dn[2];
	}
	int get3(){
		return dn[3];
	}
	int get4(){
		return dn[4];
	}
	int get5(){
		return dn[5];
	}
};

int main()
{
	int n;
	int count = 0;
	int ndice[100][6];
	string flag = "Yes";
	string quu[23] = { "WSE", "ESW", "WSSE", "SWW", "EN", "WN", "N", "SW", "W", "SSW",
		"NW", "SE", "E", "SSE", "NE", "S", "WS", "ES", "WWS", "WW", "SWS", "SES", "SS" };

	cin >> n;
	for (int i = 0; i < n; i++){          // n個のサイコロの入力
		for (int j = 0; j < 6; j++){
			cin >> ndice[i][j];
		}	
	}

	for (int i = 0; i < n; i++){                // サイコロを比べる
		for (int j = i + 1; j < n; j++){                      // Dice a()にサイコロを登録し、順次比較していく
			Dice a(ndice[j][0], ndice[j][1], ndice[j][2], 
				ndice[j][3], ndice[j][4], ndice[j][5]);

			for (int k = 0; k < 6; k++){            // 転がすこともなく同じサイコロかどうか
				if (ndice[i][k] == ndice[j][k]){
					count = count + 1;
				}
			}
			if (count == 6){     // 6面全てが一致すれば、同じサイコロ
				flag = "No";
			}
			count = 0;

			for (int l = 0; l < 23; l++){     // サイコロが取り得る全ての可能性(面の上下左右)を比較していく
				a.Result(quu[l]);

				ndice[j][0] = a.get0();
				ndice[j][1] = a.get1();
				ndice[j][2] = a.get2();
				ndice[j][3] = a.get3();
				ndice[j][4] = a.get4();
				ndice[j][5] = a.get5();

				for (int k = 0; k < 6; k++){               // 6面全てが一致すれば、同じサイコロ
					if (ndice[i][k] == ndice[j][k]){
						count = count + 1;
					}
				}
				if (count == 6){
					flag = "No";
				}
				count = 0;
			}
		}
	}
	cout << flag << endl;
	
	return 0;
}
