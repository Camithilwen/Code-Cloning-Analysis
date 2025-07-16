#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void PrintfArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if( i )
            cout << endl;
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(int a[], int n, int g)
{
    for(int i = g; i < n; i++)
    {
        int temp = a[i];
        int j = i - g;
        while(j >= 0 && temp < a[j]){
            a[j+g] = a[j];
            j -= g;
            cnt ++;
        }
        a[j+g] = temp;
    }
}

void shellSort(int a[], int n)
{
    cnt = 0;
    vector<int> G;
    int g = 1;
    do{
        G.push_back(g);
        g = 3 * g + 1;
    }while(g<n);
    
    
    cout << G.size() << endl;
    
    for(int i=G.size()-1; i>=0; i--)
    {
        if(G.size()-i-1)
            cout << " ";
        cout << G[i];
    }
    cout << endl;
    
    for(int i=G.size()-1; i>=0; i--)
    {
        insertionSort(a, n, G[i]);
    }
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; i++)
	{
	    cin >> a[i];
	}
	shellSort(a, n);
	
	cout << cnt << endl;
	PrintfArray(a, n);
	
	
	return 0;
}