#include<iostream>
#include<queue>
#include<vector>
using namespace std;
long long int gcd(long long int a, long long int b);
//int a[200000];
vector<int> graph[100000];
int flag[100000];
int main() {
	
	//F
	int n;
	cin >> n;
	int u, v;
	cin >> u >> v;
	int a, b;
	int i;

	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	u = u - 1;
	v = v - 1;
	queue<int> que;
	que.push(u);
	

	for (i = 0; i < n; i++) {
		flag[i] = -1;
	}
	flag[u] = 0;
	while (que.size()) {
		a = que.front(); que.pop();
		for (i = 0; i < graph[a].size(); i++) {
			if (flag[graph[a][i]] == -1) {
				que.push(graph[a][i]);
				flag[graph[a][i]] = flag[a] + 1;
			}
		}
	}
	vector<int> path;
	path.push_back(v);
	a = v;
	while (flag[a] != 0) {
		for (i = 0; i < graph[a].size(); i++) {
			if (flag[graph[a][i]] == flag[a] - 1) {
				a = graph[a][i];
				path.push_back(a);
				break;
			}
		}
	}
	//cout << flag[v] << endl;
	//vからuのパスができた．
	//if (flag[v] == 1) {
	//	cout << 0 << endl;
	//	return 0;
	//}
	int counter = 0;
	counter = counter + (int)((path.size() - 2) / 2);
	//cout << counter << endl;
	v = path[((path.size() - 2) / 2)];
	u = path[((path.size() - 2) / 2)+ 1 + (path.size() % 2)];
	int w = path[((path.size() - 2) / 2) + 1];

	//for (i = 0; i < path.size(); i++)cout << path[i] << ' ';
	//cout << endl;
	//cout << path.size() << 'u' << u << 'v' << v << endl;
	for (i = 0; i < n; i++) {
		flag[i] = -1;
	}
	flag[u] = 0;
	int maxflag = 0;
	que.push(u);
	while (que.size()) {
		a = que.front(); que.pop();
		for (i = 0; i < graph[a].size(); i++) {
			if ((flag[graph[a][i]] == -1) && (graph[a][i]!=v) && (graph[a][i] != w)) {
				que.push(graph[a][i]);
				flag[graph[a][i]] = flag[a] + 1;
				if (maxflag < flag[a] + 1) {
					maxflag = flag[a] + 1;
					//cout << maxflag << endl;
				}
			}
		}
	}
	//cout << counter << ' ' << maxflag << ' ' << path.size() << endl;
	//for (i = 0; i < 9; i++)cout << flag[i] << ' ';
	//cout << endl;
	counter = counter + maxflag + (path.size() % 2);
	cout << counter << endl;
	return 0;



	//E
	/*long long int N;
	cin >> N;
	long long int counter = 0;
	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	else {
		if (N == 0) {
			cout << 0 << endl;
			return 0;
		}
		else {
			N = N - (N % 10);
			N = N / 10;
			counter = counter + N;
			while (N > 0) {
				N = N - (N % 5);
				N = N / 5;
				counter = counter + N;
			}
			cout << counter << endl;
			return 0;
		}
	}
	*/

	
	//D

	/*int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	int counter = 0;
	int seek = 1;
	for (i = 0; i < n; i++) {
		if (a[i] == seek) {
			counter++;
			seek++;
		}
	}
	if (counter == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << n - counter << endl;
	return 0;*/


	//C
	/*long long int A, B;
	cin >> A >> B;
	cout <<  A * B / gcd(A, B) << endl;
	return 0;*/

	//B
	/*int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int i;
	for (i = 0; i < n; i++) {
		cout << s[i];
		cout << t[i];
	}
	cout << endl;
	return 0;*/
}
long long int gcd(long long int a,long long  int b) {
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}