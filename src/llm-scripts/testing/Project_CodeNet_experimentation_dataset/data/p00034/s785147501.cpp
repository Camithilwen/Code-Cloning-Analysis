#include<iostream>
using namespace std;

#define N 10	// üHÌ

int main()
{
	double l[N], v[2];
	double sum[N];
	double position;
	int i;

	while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&l[0],&l[1],&l[2],&l[3],&l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v[0],&v[1]) != EOF) {
		sum[0] = l[0];
		for (i = 1; i < N; i++)
			sum[i] = sum[i-1]+l[i];
		position = v[0] * sum[9] / (v[0]+v[1]);
		for (i = 0; i < N; i++)
			if (sum[i]>=position)
				break;
		i++;

		cout<<i<<endl;
	}

	return 0;
}