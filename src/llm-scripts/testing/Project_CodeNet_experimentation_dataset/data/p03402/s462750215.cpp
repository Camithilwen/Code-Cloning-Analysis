#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	int maxv = max(a, b);
	int minv = min(a, b);
	int c = minv - 1;
	int d = maxv - c;

	int count = 0;
	bool da[100][100];
	fill(da[0], da[0]+100*100, false);
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (!(count < c))
				goto end;
			int ox = j*4;
			int oy = i*4;
			da[oy+0][ox+0] = true;
			da[oy+0][ox+1] = true;
			da[oy+0][ox+2] = true;
			da[oy+1][ox+0] = true;
			da[oy+1][ox+2] = true;
			da[oy+2][ox+0] = true;
			da[oy+2][ox+1] = true;
			da[oy+2][ox+2] = true;
			count++;
		}
	}
end:

	count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 50; j++) {
			if (!(count < d))
				goto end2;
			int oy = 80+i*2;
			int ox = j*2;
			da[oy][ox] = true;
			count++;
		}
	}
end2:

  
  	printf("100 100\n");
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (minv == maxv) {
				if (da[y][x])
					putchar('#');
				else
					putchar('.');
			} else {
				if (maxv == b) {
					if (da[y][x])
						putchar('#');
					else
						putchar('.');
				} else {
					if (da[y][x])
						putchar('.');
					else
						putchar('#');
				}
			}
		}
		cout << endl;
	}

	return 0;
}