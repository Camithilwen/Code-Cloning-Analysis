#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int timer = 0;

struct needed {

	needed(int verNum) {
		for (int i = 0; i < verNum; i++) {
			visited.push_back(false);
			preNum.push_back(1 << 30);
			lowest.push_back(1 << 30);
			parent.push_back(-1);
		}
	}

	vector<bool> visited;
	vector<int> preNum; //?¨?????????????
	vector<int> lowest;
	vector<int> parent;

};

void DFS(int current, int previous, vector<int> verVal[], needed &need) {

	need.preNum[current] = timer;
	need.lowest[current] = timer;
	timer++;

	need.visited[current] = true;

	for (int i = 0; i < verVal[current].size(); i++) {
		int next = verVal[current][i];
		if (!need.visited[next]) {
			need.parent[next] = current;
			DFS(next, current, verVal, need);
			need.lowest[current] = min(need.lowest[current], need.lowest[next]);
		}
		else if (next != previous) {
			need.lowest[current] = min(need.lowest[current], need.preNum[next]);
		}
	}
}

void ArticulationPoint(vector<int> verVal[], int verNum) {

	needed need(verNum);
	DFS(0, -1, verVal, need);

	set<int> artPoints;
	int childNumOfRoot = 0;
	//root??????????????¨??¨
	for (int i = 1; i < verNum; i++) {
		int nowP = need.parent[i];
		if (nowP == 0) childNumOfRoot++;
		else if (need.preNum[nowP] <= need.lowest[i])
			artPoints.insert(nowP);
	}
	//root?????¢?????????????????????????????????????????£??????????????§?????????
	if (childNumOfRoot > 1) artPoints.insert(0);

	for (set<int>::iterator it = artPoints.begin(); it != artPoints.end(); it++)
		cout << *it << endl;
}

int main() {

	int verNum, edgeNum;
	cin >> verNum >> edgeNum;
	vector<int> verVal[100000];

	for (int i = 0; i < edgeNum; i++) {
		int firVal, secVal;
		cin >> firVal >> secVal;
		verVal[firVal].push_back(secVal);
		verVal[secVal].push_back(firVal);
	}

	ArticulationPoint(verVal, verNum);

	return 0;
}