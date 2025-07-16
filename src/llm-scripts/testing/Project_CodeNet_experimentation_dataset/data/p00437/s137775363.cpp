#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <cstring>

#define NOT_DEFINED 2
#define NORMAL 1
#define IRREGULAR 0

using namespace std;

typedef struct {
    int battery;
    int motor;
    int cable;
    bool hasSucceeded;
} Query;

struct IsSuccess {
    bool operator()(Query &a, Query &b) const {
        return (a.hasSucceeded < b.hasSucceeded);
    }
};


char parts[300];

int main() {
    while (1) {
        int i, a, b, c;
        int N;
        priority_queue<Query, vector<Query>, IsSuccess> queries;

        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c ==0) {
            return 0;
        }

        scanf("%d", &N);
        for (i=0;i<N;i++) {
            int i, j, k ,r;
            Query query;

            scanf("%d %d %d %d", &i, &j, &k, &r);
            query.battery = i-1;
            query.motor = j-1;
            query.cable = k-1;
            query.hasSucceeded = r;

            queries.push(query);
        }

        memset(parts, NOT_DEFINED, 300);

        while (!queries.empty()) {
            int i, j, k, r;
            Query query = queries.top();

            i = query.battery;
            j = query.motor;
            k = query.cable;
            r = query.hasSucceeded;

            if (r) {
                parts[i] = NORMAL;
                parts[j] = NORMAL;
                parts[k] = NORMAL;
            } else {
                if (parts[i] == NORMAL && parts[j] == NORMAL) {
                    parts[k] = IRREGULAR;
                }

                if (parts[j] == NORMAL && parts[k] == NORMAL) {
                    parts[i] = IRREGULAR;
                }

                if (parts[k] == NORMAL && parts[i] == NORMAL) {
                    parts[j] = IRREGULAR;
                }
            }

            queries.pop();
        }

        for (i=0;i<a+b+c;i++) {
            printf("%d\n", parts[i]);
        }
    }
}