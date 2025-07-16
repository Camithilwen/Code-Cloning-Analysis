#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
void dice1();
void dice2();
void dice3();
void dice4();
class DICE{
	int face[6],a;
public:
	bool operator==(const DICE&di)const{
		int cont=0;
		for(int i=0;i<6;++i){
			if(face[i]==di.face[i]){
				cont++;
			}
		}
		if(cont==6){
			return true;
		}
		else{
			return false;
		}
	}
	bool operator!=(const DICE&di)const{
		return !(*this==di);
	}
	void set(int&f,int&f1,int&f2,int&f3,int&f4,int&f5){
		face[0]=f;face[1]=f1;face[2]=f2;face[3]=f3;face[4]=f4;face[5]=f5;
	}
	void N(){
		a=face[0];
		face[0]=face[1];
		face[1]=face[5];
		face[5]=face[4];
		face[4]=a;
	}
	void E(){
		a=face[0];
		face[0]=face[3];
		face[3]=face[5];
		face[5]=face[2];
		face[2]=a;
	}
	void S(){
		a=face[0];
		face[0]=face[4];
		face[4]=face[5];
		face[5]=face[1];
		face[1]=a;
	}
	void W(){
		a=face[0];
		face[0]=face[2];
		face[2]=face[5];
		face[5]=face[3];
		face[3]=a;
	}
	void output(){
		cout<<face[0]<<endl;
	}
	int up(){
		return face[0];
	}
	void turn(){
		a=face[1];
		face[1]=face[3];
		face[3]=face[4];
		face[4]=face[2];
		face[2]=a;
	}
	int front(){
		return face[1];
	}
	int right(){
		return face[2];
	}
	void allout(){
		for(int i=0;i<6;++i){
			cout<<face[i]<<" ";
		}
		cout<<endl;
	}
	void toupper(int n){
		if(n<=3){
			a=face[0];
			face[0]=face[1];
			face[1]=face[5];
			face[5]=face[4];
			face[4]=a;
		}
		else if(n==4){
			a=face[0];
			face[0]=face[3];
			face[3]=face[5];
			face[5]=face[2];
			face[2]=a;
		}
		else if(n==5){
			a=face[0];
			face[0]=face[3];
			face[3]=face[5];
			face[5]=face[2];
			face[2]=a;
			a=face[0];
			face[0]=face[3];
			face[3]=face[5];
			face[5]=face[2];
			face[2]=a;
		}

	}
};
bool judge(DICE,DICE);
int main(){
	dice4();
	return 0;
}
void dice1(){
	DICE a;
	int d[6];string str;
	for(int i=0;i<6;++i){
		cin>>d[i];
	}
	a.set(d[0],d[1],d[2],d[3],d[4],d[5]);
	getline(cin,str);
	getline(cin,str);
	for(int i=0;i<str.size();++i){
		if(str[i]=='E'){
			a.E();
		}
		else if(str[i]=='S'){
			a.S();
		}
		else if(str[i]=='W'){
			a.W();
		}
		else if(str[i]=='N'){
			a.N();
		}
	}
	a.output();
	return;
}
void dice2(){
	DICE a;
	int d[6],p,u;
	for(int i=0;i<6;++i){
		cin>>d[i];
	}a.set(d[0],d[1],d[2],d[3],d[4],d[5]);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>p>>u;
		int k=0;
		while(1){
			k++;
			if(k<=5){
				a.E();
			}
			else{
				a.N();
			}
			if(p==a.up()){
				break;
			}
		}
		k=0;
		while(1){
			k++;
			a.turn();
			if(u==a.front()){
				break;
			}
		}
		cout<<a.right()<<endl;
	}
	return;
}
void dice3(){
	DICE a,b;
	int d[6][2];
	for(int i=0;i<2;++i){
		for(int j=0;j<6;++j){
			cin>>d[j][i];
		}
	}
	a.set(d[0][0],d[1][0],d[2][0],d[3][0],d[4][0],d[5][0]);
	b.set(d[0][1],d[1][1],d[2][1],d[3][1],d[4][1],d[5][1]);
	if(judge(a,b)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
bool judge(DICE a,DICE b){
	bool bo1=false,bo2=false;
	for(int i=0;i<6;++i){
		b.toupper(i);
		for(int j=0;j<4;++j){
			if(a==b){
				return true;
			}
			b.turn();
		}

	}
	return false;
}
void dice4(){
	int n,d[6][101];
	DICE a[101];
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<6;++j){
			cin>>d[j][i];
		}
	}
	for(int i=0;i<n;++i){
		a[i].set(d[0][i],d[1][i],d[2][i],d[3][i],d[4][i],d[5][i]);
	}
	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n;++j){
			if(judge(a[i],a[j])){
				cout<<"No"<<endl;
				return ;
			}
			else {

			}
		}
	}
	cout<<"Yes"<<endl;
	return ;
}