#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main()
{
	int n, team1, team2, score1, score2, point[101] = {0};
	vector<int> rank;
	cin >> n;
	for(int i = 0; i < n * (n - 1) / 2; i++){
		cin >> team1 >> team2 >> score1 >> score2;
		if(score1 > score2)
			point[team1] += 3;
		else if(score1 < score2)
			point[team2] += 3;
		else{
			point[team1]++;
			point[team2]++;
		}
	}

	for(int i = 0; i < n; i++)
		rank.push_back(point[i + 1]);

	stable_sort(rank.begin(), rank.end(), greater<int>());

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++){
			if(point[i] == rank[j]){
				cout << j + 1 << endl;
				break;
			}
		}
	}

	return 0;
}