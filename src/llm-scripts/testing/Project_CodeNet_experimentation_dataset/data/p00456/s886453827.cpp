#include <cstdio>
#include <queue>
using namespace std;

int main(void)
{
	priority_queue <int> w, k;
	int tmp;
	
	for (int i = 0; i < 10; i++){
		scanf("%d", &tmp);
		w.push(tmp);
	}
	for (int i = 0; i < 10; i++){
		scanf("%d", &tmp);
		k.push(tmp);
	}
	
	int sumw = 0, sumk = 0;
	for (int i = 0; i < 3; i++){
		sumw += w.top();
		w.pop();
		sumk += k.top();
		k.pop();
	}
	
	printf("%d %d\n", sumw, sumk);
	
	return (0);
}