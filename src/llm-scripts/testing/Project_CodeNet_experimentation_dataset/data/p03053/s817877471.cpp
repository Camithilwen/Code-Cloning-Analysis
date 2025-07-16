#include <iostream>
#include <vector>
#include <string>
using namespace std;

class edge;

class vertex{
    public:
        vector<edge*> edges;
        int color;
        vertex(int _color){
            color = _color;
        }
};

class edge{
    public:
        vertex *to;
        edge(vertex *_to){
            to = _to;
        }
};

class list_node{
    public:
        list_node *prev,*next;
        vertex *data;
        list_node(list_node *_prev,list_node *_next,vertex *_data){
            prev = _prev;
            next = _next;
            data = _data;
        }
};

class list{
    public:
        list_node *back,*front;
        list(){
            back = new list_node(0,0,0);
            front = new list_node(0,back,0);
            back->prev = front;
        }
        list_node *get_first(){
            return front->next;
        }
        list_node *get_last(){
            return back->prev;
        }
        void push_back(vertex *data){
            list_node *node = back->prev;
            node->next = new list_node(node,back,data);
            back->prev = node->next;
        }
        bool isEmpty(){
            if(front->next == back) return true;
            return false;
        }
};

int bfs(list l){
    int count = 0;
    list *L = new list[10000];
    L[0] = l;
    while(true){
        for(list_node *j = L[count].get_first(); j != L[count].back; j = j->next){
            vertex *v = j->data;
            for(int k = 0; k < v->edges.size(); k++){
                vertex *to = v->edges[k]->to;
                if(to->color) continue;
                to->color = 1;
                L[count+1].push_back(to);
            }
        }
        if(L[count+1].isEmpty()) break;
        count++;
    }
    return count;
}

int main(){
    int H,W,color;
    string str;
    cin >> H >> W;
    list l;
    vertex *A[H+2][W+2];
    for(int i = 0; i <= H+1; i++){
        if(i != 0 && i != H+1) cin >> str;
        for(int j = 0; j <= W+1; j++){
            if(i  == 0 || j == 0 || i == H+1|| j == W+1){
                A[i][j] = new vertex(1);
            }else{
                if(str[j-1] == '.') color = 0;
                else color = 1;
                A[i][j] = new vertex(color);
            }
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(A[i][j]->color) l.push_back(A[i][j]);
            A[i][j]->edges.push_back(new edge(A[i-1][j]));
            A[i][j]->edges.push_back(new edge(A[i][j+1]));
            A[i][j]->edges.push_back(new edge(A[i+1][j]));
            A[i][j]->edges.push_back(new edge(A[i][j-1]));
        }
    }

    cout << bfs(l) << endl;
    
}