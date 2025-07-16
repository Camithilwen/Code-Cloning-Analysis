#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
//#include <cmath>
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_N = 2050;
const int MAX_Q = 200000;
int N, M, Q;

char S[MAX_N][MAX_N];
int x1[MAX_Q], y1[MAX_Q], x2[MAX_Q], y2[MAX_Q];

int ac_node[MAX_N][MAX_N] = {};
int ac_edge_hor[MAX_N][MAX_N] = {};
int ac_edge_ver[MAX_N][MAX_N] = {};

int main(int argc, char **argv) {
    std::cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> S[i][j];
        }
    }

    for (int i = 1; i <= Q; i++) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    for (int i = 1; i <= N; i++) {
        int ac_tmp = 0;
        for (int j = 1; j <= M; j++) {
            if (S[i][j] == '1') {
                ac_tmp++;
            }
            ac_node[i][j] = ac_node[i-1][j] + ac_tmp;
        }

        int ac_tmp_edge_hor = 0;
        int ac_tmp_edge_ver = 0;
        for (int j = 1; j <= M; j++) {
            if (S[i][j] == '1' && S[i][j-1] == '1') {
                ac_tmp_edge_ver++;
            }
            if (S[i][j] == '1' && S[i-1][j] == '1') {
                ac_tmp_edge_hor++;
            }
            ac_edge_ver[i][j] = ac_edge_ver[i-1][j] + ac_tmp_edge_ver;
            ac_edge_hor[i][j] = ac_edge_hor[i-1][j] + ac_tmp_edge_hor;
        }
    }

    for (int i = 1; i <= Q; i++) {
        int node_num = ac_node[x2[i]][y2[i]] - ac_node[x2[i]][y1[i] - 1] - ac_node[x1[i] - 1][y2[i]] + ac_node[x1[i] - 1][y1[i] - 1];
        int edge_num_hor = ac_edge_hor[x2[i]][y2[i]] - ac_edge_hor[x2[i]][y1[i] - 1] - ac_edge_hor[x1[i]][y2[i]] + ac_edge_hor[x1[i]][y1[i] - 1];
        int edge_num_ver = ac_edge_ver[x2[i]][y2[i]] - ac_edge_ver[x2[i]][y1[i]] - ac_edge_ver[x1[i] - 1][y2[i]] + ac_edge_ver[x1[i] - 1][y1[i]];

        //std::cout << "check:" << node_num << " " << edge_num << std::endl;

        std::cout << node_num - edge_num_hor - edge_num_ver << std::endl;
    }

    return 0;
}