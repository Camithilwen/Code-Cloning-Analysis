#include <iostream>

using namespace std;

int order[4000];

bool search(int);

class Member {
public:
	Member() {sum = 0;}
	
	void add(long price, long num) {
		sum += (long long int)price*num;
	}
	
	bool milion()
	{
		if (sum >= 1000000) return true;
		else return false;
	}
	
private:
	long long int sum;
	int id;
};


bool search(int num)
{
	for (int i=0; i<4000; i++) 
		if (order[i] == num ) return true;
	
	return false;
	
}

int main()
{
	int n, idx, memNum;
	long price, num;
	bool nothing;

	
	ios::sync_with_stdio();
	
	while (1) {
		Member *member = new Member[4000];
		memNum=0;
		nothing =true;
		
		for (int i=0; i<4000; i++) order[i] = -1;
		
		if (cin >> n, !n) break;
		for (int i=0; i<n; i++) {
			scanf("%d %ld %ld", &idx, &price, &num);
			member[idx].add(price, num);
			if (!search(idx)) order[memNum++] = idx;
		}
		
		for (int i=0; i<4000 && order[i] > 0; i++) 
			if (member[order[i]].milion()) { cout << order[i] << endl; nothing = false; }
		if (nothing) cout << "NA" << endl;
	}
}