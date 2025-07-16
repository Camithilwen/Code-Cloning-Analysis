#include <bits/stdc++.h>
using namespace std;

vector<int> primes={2,3,5,7};
int primes_extend(int calc_from, int calc_to);
int factoring(int n, map<int,int> &factors);

const int combination_max=100000+1000;
const int combination_modulo=1000000007;
vector<int64_t> factorials(combination_max);
vector<int64_t> factorials_inv(combination_max);
vector<int64_t> inverse(combination_max);
int combination_mod(int n, int k);
int prepare_combination_mod();
	

int main()
{
	int n,m;
	cin >> n >> m;

	primes_extend(10,100);
	primes_extend(100,10000);
	primes_extend(10000,32767);

	map<int,int> factors;
	factoring(m,factors);
	for (pair<int,int> p:factors)
	{
	 	// fprintf(stderr,"%d: %d\n",p.first,p.second);
	}

	prepare_combination_mod();

	int64_t patterns=1;
	for (pair<int,int> p:factors)
	{
		int c=combination_mod(p.second+n-1,n-1);
		// fprintf(stderr,"%d: %d patterns\n",p.first,c);
		patterns*=c;
		patterns%=combination_modulo;
	}
	cout << patterns << endl;
}

int primes_extend(int calc_from, int calc_to)
{

	for (int i=calc_from;i<=calc_to;++i)
	{
		int j;
		int loop_max=sqrt(i);
		for (j=0;(primes[j]<=loop_max)&&(j<primes.size());++j)
		{
			if ((i%primes[j])==0)
			{
				// not prime...
				break;
			}
		}
		if ((j>=primes.size())||(primes[j]>loop_max))
		{
			primes.push_back(i);
		}
	}
	//fprintf(stderr,"count: %d\n",primes.size());
}

int factoring(int n, map<int,int> &factors)
{
	int maxfactor=sqrt(n);
	for (int i=0;(n>1)&&(primes[i]<=maxfactor);++i)
	{
		while ((n%primes[i])==0)
		{
			n/=primes[i];
			factors[primes[i]]++;
		}
	}
	if (n!=1)
	{
		factors[n]++;
	}

	return 0;
}

int prepare_combination_mod()
{
	factorials[0]=1;
	factorials[1]=1;
	factorials_inv[0]=1;
	factorials_inv[1]=1;
	inverse[1]=1;
	for (int i=2;i<combination_max;++i)
	{
		factorials[i]=factorials[i-1]*i%combination_modulo;
		inverse[i]=combination_modulo - inverse[combination_modulo%i]*(combination_modulo/i)%combination_modulo;
		factorials_inv[i]=factorials_inv[i-1]*inverse[i]%combination_modulo;
	}
}

int combination_mod(int n, int k)
{
	return factorials[n]*(factorials_inv[k]*factorials_inv[n-k]%combination_modulo)%combination_modulo;
}




