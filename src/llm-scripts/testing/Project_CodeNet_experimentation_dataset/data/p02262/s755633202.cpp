#include<iostream>
#include<vector>
using namespace std;

void show(int arr[], int N){
	for(int i=0; i<N; i++)
		if(i<N-1)
			cout<<arr[i]<<' '<<flush;
		else
			cout<<arr[i]<<flush;
	cout<<endl;
}


void swap(int& a, int& b){
	int t=a;
	a=b;
	b=t;
}


int ShellSort(int* arr, int N);
int InsertionSort_r(int* arr, int N, int r);

int main()
{
	int N;cin>>N;

	int* arr= new int[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	int count=ShellSort(arr, N);

	cout<<count<<endl;

	for( int i=0; i<N; i++)
		cout<<arr[i]<<endl;

	delete[] arr;
}


int ShellSort(int* arr, int N)
{
	int counter=0;


	vector<int> range;

	for( int i=1; i<=N; i= i*3 +1 )
		range.push_back(i);






	
	cout<<range.size()<<endl;

	for( int i=range.size() -1; i >=0; i-- )
		cout<<range[ i ]<<' '<<flush;
	cout<<endl;







	 

	for( int i=range.size() -1; i>=0; i-- ) 
		counter=InsertionSort_r(arr, N, range[ i ]);
	
	return counter;

	
	



	
}

int InsertionSort_r(int arr[], int N, int r)
{

	static int counter=0;
	int compindex;
	int comp;
	int j;

	
	for( int i=0; i<r; i++) {


		for( int compindex=N- r -1 -i ; compindex> -1; compindex-=r ){
			
			comp=arr[compindex];
			j=r;
			for( ; compindex+j<N; j+=r ){

				if(comp > arr[compindex+j]){
					arr[compindex + j -r] = arr[compindex + j];
					counter++;
				}
				else
					break;
				
			}
			arr[compindex + j - r] = comp;

		


		}
	}
	return counter;
}
/* ?§£??????????????????????????????
	  o x x o x x x *
	  o x x o x x o *
	  x o x x o x x
	  x x o x x o x
  ??¨???????????????????????????????????????????????§???
  	  o x x o x x x *
	  x o x x o x x
	  x x o x x o x
	  o x x o x x o *
?????¨?????????????§£?????????
????????????????????¨????????????????????????(0.2?§????????§£?????????????????????????)
   
int InsertionSort_r(int arr[], int N, int r)
{
	static int cnt=0;
	bool changed=false;
	for( int compindex=r; compindex<N; compindex++) {

		int comp= arr[compindex];

		int j=compindex - r;

		for( ; j>=0; j-=r ) {
			if(arr[j] > comp){
				arr[ j+r ]=arr[j];
				cnt++;
				changed=true;
			}
			else
				break;
		}

		arr[ j+r ] =comp;


		changed=false;
	}
	return cnt;
}
*/