#include <bits/stdc++.h>

int main(){
    int N, u, v;
    std::cin >> N >> u >> v;
    u--; v--;
    std::vector< std::vector< int > > AB(N);
    for(int i=1; i<N; i++){
        int tmpa, tmpb;
        std::cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        AB[tmpa].push_back(tmpb);
        AB[tmpb].push_back(tmpa);
    }
    
    std::vector< int > min_dist(N, 1e9);
    std::vector< int > min_route;
    std::deque< int > pos;
    std::deque< int > prepos;
    std::deque< int > dist;
    std::vector< int > route;
    pos.push_back(v);
    prepos.push_back(-1);
    dist.push_back(0);
    
    while(!pos.empty()){
        int c_pos = pos[0];
        int c_prepos = prepos[0];
        int c_dist = dist[0];
        pos.pop_front();
        prepos.pop_front();
        dist.pop_front();
        
        if(min_dist[c_pos] <= c_dist){
            continue;
        }
        
        route.resize(c_dist);
        route.push_back(c_pos);
        
        min_dist[c_pos] = c_dist;
        if(c_pos == u){
            min_route = route;
            break;
        }
        
        for(int i=0; i<AB[c_pos].size(); i++){
            if(AB[c_pos][i] == c_prepos){
                continue;
            }
            pos.push_front(AB[c_pos][i]);
            prepos.push_front(c_pos);
            dist.push_front(c_dist+1);
        }
    }
    
    int center = (min_route.size() % 2 == 0) ? min_route[min_route.size() / 2] : min_route[min_route.size() / 2 + 1];
    int pre_center = (min_route.size() % 2 == 0) ? min_route[min_route.size() / 2 - 1] : min_route[min_route.size() / 2];
    int center_dist = (min_route.size() % 2 == 0) ? min_route.size() / 2 : min_route.size() / 2 + 1;
    
    pos.clear();
    prepos.clear();
    dist.clear();
    pos.push_back(center);
    prepos.push_back(-1);
    dist.push_back(0);
    min_dist.assign(N, 1e9);
    int max_dist = 0;
    
    while(!pos.empty()){
        int c_pos = pos[0];
        int c_prepos = prepos[0];
        int c_dist = dist[0];
        pos.pop_front();
        prepos.pop_front();
        dist.pop_front();
        
        if(c_pos == pre_center){
            continue;
        }
        if(min_dist[c_pos] <= c_dist){
            continue;
        }
        
        min_dist[c_pos] = c_dist;
        if(max_dist < c_dist){
            max_dist = c_dist;
        }
        
        for(int i=0; i<AB[c_pos].size(); i++){
            if(AB[c_pos][i] == c_prepos){
                continue;
            }
            pos.push_back(AB[c_pos][i]);
            prepos.push_back(c_pos);
            dist.push_back(c_dist+1);
        }
    }
    
    std::cout << center_dist + max_dist - 1 << std::endl;
    
    
    return 0;
    
}
