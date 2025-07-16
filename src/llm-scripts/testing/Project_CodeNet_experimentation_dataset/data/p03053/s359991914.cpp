#include<iostream>
#include<queue>
using namespace std;

int H,W;
char A[1005][1005];

int dist[1005][1005];
bool visited[1005][1005];
int white_cnt=0;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

class Node{
public:
    int x,y;
    Node(int a, int b):x(a),y(b){}
};

void input(){
    cin>>H>>W;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            cin>>A[i][j];
        }
    }
}

void init(){
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            dist[i][j]=-1;
        }
    }
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            visited[i][j]=false;
        }
    }
}

void bfs(){
    init();
    queue<Node> que;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(A[i][j]=='#'){
                Node temp(j,i);
                que.push(temp);
                visited[i][j]=true;
                dist[i][j]=0;
            }
        }
    }
    while(!que.empty()){
        Node cur=que.front();
        que.pop();
        int cur_x=cur.x;
        int cur_y=cur.y;
        for(int i=0;i<4;++i){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            bool b=0<=next_x&&next_x<W&&0<=next_y&&next_y<H;
            if(A[next_y][next_x]=='#'||visited[next_y][next_x]||!b) continue;
            visited[next_y][next_x]=true;
            dist[next_y][next_x]=dist[cur_y][cur_x]+1;
            Node next(next_x,next_y);
            que.push(next);
        }
    }   
}

int max_search(){
    int ans=0;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            ans=ans<dist[i][j]?dist[i][j]:ans;
        }
    }
    return ans;
} 

void output(){
    cout<<max_search()<<endl;
}

int main(){
    input();
    bfs();
    output();
}