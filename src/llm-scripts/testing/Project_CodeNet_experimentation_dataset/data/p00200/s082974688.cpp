#define NODE 0
#define WEIGHT 1
#define COST_IDX 0
#define TIME_IDX 1
#define P_IDX 0
#define Q_IDX 1
#define R_IDX 2
#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int weights[101][101][2];
int min_w[101][101][2];
int requests[200][3];

struct heap_queue {
  int arr[101];
  int *cmp_val;
  int lookup[101];
  int size=0;
};

void heap_push(int elm, heap_queue &q) {
  q.arr[q.size] = elm;
  int above, i = q.size++;
  while (i && q.cmp_val[q.arr[(above=(i-1)>>1)]] > q.cmp_val[elm]) {
    q.arr[i] = q.arr[above];
    q.lookup[q.arr[i]] = i;
    i = above;
  }
  q.arr[i] = elm;
  q.lookup[elm] = i;
}

int heap_pop(heap_queue &q) {
  int popped = q.arr[0];
  int elm = q.arr[--q.size];
  int below, i = 0;
  while ((below=(i<<1)+1) < q.size) {
    if (below+1 < q.size && q.cmp_val[q.arr[below+1]] < q.cmp_val[q.arr[below]])
      below++;
    if (q.cmp_val[q.arr[below]] >= q.cmp_val[elm])
      break;
    q.arr[i] = q.arr[below];
    q.lookup[q.arr[i]] = i;
    i = below;
  }
  q.arr[i] = elm;
  q.lookup[elm] = i;
  return popped;
}

void change_val(int elm, heap_queue &q) {
  int above, i = q.lookup[elm];
  while (i && q.cmp_val[q.arr[(above=(i-1)>>1)]] > q.cmp_val[elm]) {
    q.arr[i] = q.arr[above];
    q.lookup[q.arr[i]] = i;
    i = above;
  }
  q.arr[i] = elm;
  q.lookup[elm] = i;
}

bool read_input() {
  cin >> n >> m;
  if (n*m == 0) 
    return false;
  memset(weights, 0, sizeof(int)*101*101*2);
  memset(min_w, 0, sizeof(int)*101*101*2);
  for (int i = 0; i < n; i++) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    weights[a][b][COST_IDX] = weights[b][a][COST_IDX] = c;
    weights[a][b][TIME_IDX] = weights[b][a][TIME_IDX] = t;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> requests[i][P_IDX] >> requests[i][Q_IDX] >> requests[i][R_IDX];
  }
  return true;
}

int resolve_request(int i_th) {
  int p, q, r;
  p = requests[i_th][P_IDX];
  q = requests[i_th][Q_IDX];
  r = requests[i_th][R_IDX];

  if (min_w[p][q][r])
    return min_w[p][q][r];

  int weight_sum_map[101];
  memset(weight_sum_map, -1, sizeof(int)*101);
  
  /* starting node has weight_sum of 0 */
  weight_sum_map[p] = 0;

  int in_queue[101] = {};
  heap_queue heap_q;
  heap_q.cmp_val = weight_sum_map;
  heap_push(p, heap_q);
  in_queue[p] = 1;

  while (heap_q.size) {
    int current_node = heap_pop(heap_q);
    in_queue[current_node] = 0;
    int weight_sum = weight_sum_map[current_node];
    min_w[p][current_node][r] = weight_sum;

    if (current_node == q)
      break;
    for (int i = 1; i < 101; i++) {
      if (!weights[current_node][i][r]) 
	continue;
      int adj_node = i;
      int w = weights[current_node][adj_node][r];
      int new_weight_sum =  weight_sum + w;
      if (weight_sum_map[adj_node] == -1 || new_weight_sum < weight_sum_map[adj_node]) {
	weight_sum_map[adj_node] = new_weight_sum;
	if (!in_queue[adj_node]) {
	  heap_push(adj_node, heap_q);
	  in_queue[adj_node] = 1;
	} else {
	  change_val(adj_node, heap_q);
	}
      }
    }
  }
  return weight_sum_map[q];
}

void solve() {
  //cout << endl;
  for (int i = 0; i < k; i++)
    cout << resolve_request(i) << endl;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  while(read_input()) {
    solve();
  }
  return 0;
}