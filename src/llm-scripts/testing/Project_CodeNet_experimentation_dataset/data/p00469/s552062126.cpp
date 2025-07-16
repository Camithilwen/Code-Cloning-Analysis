#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, k, a[11], b[11];
	while(1)
	{
		set<int> s;
		cin >> n >> k;
		if(n==0 && k==0) break;
		else
		{
			for(int i=0; i<n; i++)
			{
				cin >> a[i];
				if(a[i]>9) b[i]=2;
				else b[i]=1;
			}
			for(int i=0; i<n; i++)
			{
				int x=0;
				x=a[i];
				x*=10;
				for(int j=0; j<n; j++)
				{
					int y=x;
					if(j==i) continue;
					if(b[j]==2) y*=10;
					y+=a[j];
					if(k==2) s.insert(y);
					y*=10;
					for(int l=0; l<n; l++)
					{
						int z=y;
						if(l==i || l==j) continue;
						if(b[l]==2) z*=10;
						z+=a[l];
						if(k==3) s.insert(z);
						z*=10;
						for(int m=0; m<n; m++)
						{
							int w=z;
							if(m==i || m==j || m==l) continue;
							if(b[m]==2) w*=10;
							w+=a[m];
							if(k==4) s.insert(w);
						}
					}
				}
			}
			cout << s.size() << endl;
		}
	}
	return 0;
}