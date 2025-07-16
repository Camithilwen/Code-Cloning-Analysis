/*#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

typedef pair<int, int> P;
typedef pair<long, long> LP;
typedef pair<int, P> PP;
typedef pair<long, LP> LPP;



int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };


int H = 0;
int M = 0;
int S = 0;

void input(void) {
	CI H >> M >> S;

	return;
}


int main(void) {
	int sum = 0;
	int remain = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;

	while (1) {
		input();
		if (H == -1) {
			return 0;
		}
		sum = H * 3600 + M * 60 + S;
		remain = 2 * 3600 - sum;
		second = remain % 60;
		remain -= remain % 60;
		remain /= 60;
		minute = remain % 60;
		remain -= remain % 60;
		remain /= 60;
		hour = remain
	}

	return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

typedef pair<int, int> P;
typedef pair<long, long> LP;
typedef pair<int, P> PP;
typedef pair<long, LP> LPP;



int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };


int H = 0;
int M = 0;
int S = 0;

void input(void) {
CI H >> M >> S;

return;
}


int main(void) {
int sum = 0;
int remain = 0;
int hour = 0;
int minute = 0;
int second = 0;

while (1) {
input();
if (H == -1) {
return 0;
}
sum = H * 3600 + M * 60 + S;
remain = 2 * 3600 - sum;
second = remain % 60;
remain -= remain % 60;
remain /= 60;
minute = remain % 60;
remain -= remain % 60;
remain /= 60;
hour = remain
}

return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;



int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };



const long long int III = 1000010;

string str;
void input(void) {
	CI str;
	return;
}


int main(void) {
	input();
	long long int f_j = 0;
	long long int f_o = 0;
	long long int f_i = 0;

	long long int max_k = 0;for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'J') {
			if (f_o == 0 && f_i == 0) {
				f_j++;
			}
			if (f_o != 0 || f_i != 0) {
				f_j = 1;
				f_o = 0;
				f_i = 0;
			}
		}
		else {
			if (f_j > 0 && f_o != f_j && f_i == 0 && str[i] == 'O') {
				f_o++;
			}
			else {
				if (f_o > 0 && f_i != f_o && str[i] == 'I') {
					f_i++;
					if (f_j >= f_o && f_o == f_i) {
						if (f_o > max_k) {
							max_k = f_o;
						}
						f_j = 0;
						f_o = 0;
						f_i = 0;
					}
				}
				else {

					f_j = 0;
					f_o = 0;
					f_i = 0;

				}
			}
		}
	}

	CO max_k E


	return 0;
}