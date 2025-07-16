#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>
 
using namespace std;

pair <long long, long long> xy[100];
long long x[100];
long long y[100];
vector <pair <long long, long long> > c_hull;
 
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T,typename U>                                                   
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}
 
 
long long cross(pair <long long, long long> xy1, pair <long long, long long> xy2){
    return xy1.first * xy2.second - xy1.second * xy2.first;
}
 
long long dot(pair <long long, long long> xy1, pair <long long, long long> xy2){
    return xy1.first * xy2.first + xy1.second * xy2.second;
}
 
double norm(pair <long long, long long> xy){
    return sqrt((double)(xy.first * xy.first) + (double) (xy.second * xy.second));
}
 
void convex_hull(int N){
    sort(xy, xy + N);
 
    int k = 0;
    c_hull.resize(2 * N);
    for(int i = 0; i < N; i++){
        while(k > 1 && cross(c_hull[k - 1] - c_hull[k - 2], xy[i] - c_hull[k - 1]) <= 0){
            k--;
        }
        c_hull[k] = xy[i];
        k++;
    }
    int lower_half = k;
    for(int i = N - 2; i >= 0; i--){
        while(k > lower_half && cross(c_hull[k - 1] - c_hull[k - 2], xy[i] - c_hull[k - 1]) <= 0){
            k--;
        }
        c_hull[k] = xy[i];
        k++;
    }
    c_hull.resize(k - 1);
}
 
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> xy[i].first >> xy[i].second;
        x[i] = xy[i].first;
        y[i] = xy[i].second;
    }
 
    convex_hull(N);
 
    map <pair <long long, long long>, double> ans;
    if(c_hull.size() == 2){
        ans[c_hull[0]] = 0.5;
        ans[c_hull[1]] = 0.5;
    } else {
      for(int i = 1; i < c_hull.size() + 1; i++){
        double cos_value = (double) dot(c_hull[i % c_hull.size()] - c_hull[i - 1], c_hull[(i + 1) % c_hull.size()] - c_hull[i % c_hull.size()]) 
            / norm(c_hull[i % c_hull.size()] - c_hull[i - 1]) / norm(c_hull[(i + 1) % c_hull.size()] - c_hull[i % c_hull.size()]);
        double prob = acos(cos_value) / (2 * M_PI);
        ans[c_hull[i % c_hull.size()]] = prob; 
      }
    }
 
 
    for(int i = 0; i < N; i++){
        if(ans.find(make_pair(x[i], y[i])) == ans.end()){
            cout << fixed << setprecision(17) << 0.0 << endl;
        } else {
            cout << fixed << setprecision(17) << ans[make_pair(x[i], y[i])] << endl;
        }
    }
    
 
    return 0;
}