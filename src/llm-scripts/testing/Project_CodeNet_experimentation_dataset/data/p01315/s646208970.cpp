#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef struct{
	string name;
	int p,abc,de,f,s,m;
	int sum;
	double KORITU;	//sum(収入) / 時間(abc+de)+付加時間(de*(m-1)
}K;

int main(){
	int n;
	int A,B,C,D,E;
	while(1){
	cin >> n;
	if(n==0)break;
	K data[51];
	K temp;
	for(int i=0;i<n;i++){
		cin >> data[i].name >> data[i].p >> A >> B >> C >> D >> E >> data[i].f >> data[i].s >> data[i].m;
		data[i].abc=A+B+C;
		data[i].de=D+E;

		data[i].sum= data[i].f * data[i].s * data[i].m - data[i].p;
		data[i].KORITU = (double)data[i].sum / (double)(data[i].abc+data[i].de + data[i].de*(data[i].m-1) );
	}
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(data[j].KORITU > data[j-1].KORITU){
				temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
			}
		}
	}
	for(int i=0;i<n-1;i++){
	for(int j=n-1;j>i;j--){
		if(data[j].KORITU==data[j-1].KORITU&& data[j].name < data[j-1].name){
			temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
		}
	}
	}
	for(int i=0;i<n;i++){
		cout << data[i].name << endl;
	}
	cout << "#" << endl;
	}
}