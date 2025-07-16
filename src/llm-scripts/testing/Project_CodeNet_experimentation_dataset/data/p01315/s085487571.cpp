#include <iostream>
#include <string>

using namespace std;

void swapD(double *a,double *b){
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapString(string *a,string *b){
	string tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	int n;
	string str[60];
	double data[60];
	for(int i=0;i<60;i++){
		data[i]=10000000;
	}

	while(cin>>n){
		if(n==0)break;

	for(int i=0;i<n;i++){
		data[i]=0;
		int p,a,b,c,d,e,f,s,m;

		cin>>str[i]>>p>>a>>b>>c>>d>>e>>f>>s>>m;

		int cnt=0;

		cnt = a+b+c+d+e;
		data[i]=s*f;
		m--;
		for(int j=0;j<m;j++){
			cnt+=(d+e);
			data[i]+=f*s;		}

		data[i]-=p;

		data[i]/=(double)cnt;
	}

	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(data[j]>=data[j-1] ){
				swapD(&data[j],&data[j-1]);
				swapString(&str[j],&str[j-1]);
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(data[j]>=data[j-1] && str[j]<=str[j-1]){
				swapD(&data[j],&data[j-1]);
				swapString(&str[j],&str[j-1]);
			}
		}
	}


	for(int i=0;i<n;i++){
		//cout<<str[i]<<" "<<data[i]<<endl;
		cout<<str[i]<<endl;
	}

	cout<<"#"<<endl;
	}


	return 0;
}