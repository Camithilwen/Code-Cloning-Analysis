#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int n, k;

int main(){
	while(1){
		scanf("%d %d", &n, &k);
		if(n == 0 && k == 0) break;

		vector<string> v;
		set<string> num;
		for(int i=0; i<n; i++){
			char tmp[3];
			scanf("%s", tmp);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		do{

			string tmp = "";
			for(int i=0; i<k; i++)
				tmp += v[i];
			num.insert(tmp);

		}while(next_permutation(v.begin(), v.end()));

		printf("%lu\n", num.size());
	}
	return 0;
}