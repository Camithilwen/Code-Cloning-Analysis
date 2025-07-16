#include <iostream>
#include <string>
using namespace std;

void shake(int D[], char c) {
		int tmp;
		switch (c) {
				case 'S':
						tmp = D[0];
						D[0] = D[4];
						D[4] = D[5];
						D[5] = D[1];
						D[1] = tmp;
						break;
				case 'E':
						tmp = D[0];
						D[0] = D[3];
						D[3] = D[5];
						D[5] = D[2];
						D[2] = tmp;
						break;
				case 'W':
						tmp = D[0];
						D[0] = D[2];
						D[2] = D[5];
						D[5] = D[3];
						D[3] = tmp;
						break;
				case 'N':
						tmp = D[0];
						D[0] = D[1];
						D[1] = D[5];
						D[5] = D[4];
						D[4] = tmp;
						break;
				case 'R':
						tmp = D[1];
						D[1] = D[3];
						D[3] = D[4];
						D[4] = D[2];
						D[2] = tmp;
						break;
				case 'L':
						tmp = D[1];
						D[1] = D[2];
						D[2] = D[4];
						D[4] = D[3];
						D[3] = tmp;
						break;
		}
}

void print(int D[], int n)
{
		int i;
		cout << "\n---" << n << "---\n";
		for (i=0; i<6; i++) cout << "D[" << i << "]:" << D[i] << "\n";
}

int main()
{
		int n;
		cin >> n;
		int D[n][6], i, j, x, y;
		bool is=false;
		string op;
		for (i=0; i<n; i++) for (j=0; j<6; j++) cin >> D[i][j];

		for (x=0; x<n; x++) {
				for (y=0; y<n; y++) {
						if (x==y) break;

						op = "NNNNRNNNN";
						for (i=0; i<op.size(); i++) {
								if (D[x][0]==D[y][0]&&D[x][5]==D[y][5]) break;
								else shake(D[y], op[i]);
						}

						op = "RRRR";
						for (i=0; i<op.size(); i++) {
								if (D[x][0]==D[y][0]&&D[x][1]==D[y][1]) {
										if (D[x][2]==D[y][2]&&D[x][3]==D[y][3]) {
										if (D[x][4]==D[y][4]&&D[x][5]==D[y][5]) {
										is=true;
										break;
										}
										}
								}
								shake(D[y], op[i]);
						}
						if (is) break;
				}
				if (is) break;
		}

		if (is) cout << "No\n";
		else cout << "Yes\n";
}