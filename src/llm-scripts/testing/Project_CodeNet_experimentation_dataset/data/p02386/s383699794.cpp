#include <iostream>
#include <vector>
#include <string>
using namespace std;


class dice {
public:
	dice(int* a) {
		set(a[0], a[1], a[2], a[3], a[4], a[5]);
	}
	dice(int& a, int& b, int& c, int& d, int &e, int& f) {
		set(a, b, c, d, e, f);
	}
	void turn(int n) {
		if (n < 4)
		{
			turndice(n);
			return;
		}
		switch (n)
		{
		case 'N':
			turndice(0);
			break;
		case 'E':
			turndice(1);
			break;
		case 'S':
			turndice(2);
			break;
		case 'W':
			turndice(3);
			break;
		}

	}

	void turn(const char* str)
	{
		for (size_t i = 0; str[i] != '\0' ; i++)
		{
			turn(str[i]);
		}
	}

	int getcurrent(int n = 0) { return label[n]; }

public:
	int topfronttoright(const int & top, const int & front) {
		char n3[] = { "NES" };
		const char ne[][3] = { "N","N","N","E","EE" };

		for (size_t i = 0; i < 6; i++)
		{
			if (top == getcurrent())
				for (size_t j = 0; j < 4; j++)
				{
					if (front == getcurrent(1))
					{		
						return  getcurrent(2);
					}
					turn(n3);
				}
			turn(ne[i]);
		}

		return 0;
	}

	bool cmper(dice b) {
		char n3[] = { "NES" };
		const char ne[][3] = { "N","N","N","E","EE" };

		for (size_t i = 0; i < 6; i++)
		{
			if (b.getcurrent() == getcurrent())
				for (size_t j = 0; j < 4; j++)
				{
					if (b.getcurrent(1) == getcurrent(1) &&
						b.getcurrent(2) == getcurrent(2) &&
						b.getcurrent(3) == getcurrent(3) &&
						b.getcurrent(4) == getcurrent(4) &&
						b.getcurrent(5) == getcurrent(5) )
					{
						return  true;
					}
					turn(n3);
				}
			turn(ne[i]);
		}

		return false;
	}

private:
	int label[6];

	void set(int& a, int& b, int& c, int& d, int &e, int& f) {
		label[0] = a; 
		label[1] = b; 
		label[2] = c; 
		label[3] = d; 
		label[4] = e; 
		label[5] = f; 
	}
	void turndice(int n)
	{
		int m = (n > 1) ? n - 2 : n + 2;
		int f[] = { 1, 3, 4, 2 };
		int tmp;

		tmp = label[0];
		label[0] = label[f[n]];
		label[f[n]] = label[5];
		label[5] = label[f[m]];
		label[f[m]] = tmp;
	}

};

#define D

#ifdef D
int main(void)
{
	int n;
	cin >> n;
	vector<dice> arr;
	arr.reserve(n);
	int label[6];
	for (size_t i = 0; i < n; i++)
	{
		for (auto &a : label)
			cin >> a;
		dice d(label);
		arr.push_back(d);
	}

	bool flag = true;
	for (size_t i = 0; i < n -1 && flag; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if (arr[i].cmper(arr[j]))
				flag = false;
		}
	}
	if (!flag)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}
#endif // D