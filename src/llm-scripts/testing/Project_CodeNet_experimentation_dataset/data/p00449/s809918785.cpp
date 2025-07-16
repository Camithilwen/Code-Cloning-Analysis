#include "stdio.h"
#include"queue"
#include "climits"
using namespace std;

queue<int>Q;

int island;
int query;
int kind;
int start;
int goal;
int connect[101][101] = {};
int price;
int dis[101] = {};

int main() {
	scanf("%d %d", &island, &query);
	while (island != 0) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				connect[i][j] = INT_MAX;
			}
		}
		for (int i = 0; i < query; i++) {
			scanf("%d", &kind);
			if (kind == 1) {
				scanf("%d %d %d", &start, &goal, &price);
				if (connect[start][goal] > price) {
					connect[start][goal] = price;
					connect[goal][start] = price;
				}
			}
			else {
				scanf("%d %d", &start, &goal);
				Q.push(start);
				for (int i = 1; i < 101; i++) {
					dis[i] = INT_MAX;
				}
				dis[start] = 0;
				while (!Q.empty()) {
					for (int i = 1; i <= island; i++) {
						if (connect[Q.front()][i] != INT_MAX) {
							if (dis[i] > dis[Q.front()] + connect[Q.front()][i]) {
								dis[i] = dis[Q.front()] + connect[Q.front()][i];
								Q.push(i);
							}
						}
					}
					Q.pop();
				}
				if (dis[goal] == INT_MAX)printf("-1\n");
				else printf("%d\n", dis[goal]);
			}
		}
		scanf("%d %d", &island, &query);
	}
	return 0;
}