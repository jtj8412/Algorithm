//----------------------------------------------------------------------------------
// [ DepthFirstSearch ]
//
// 시간복잡도: O(V+E) (V는 정점의 개수, E는 간선의 개수)
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int* p_visited, int find_v, const vector<vector<int>>& edges) {
    if (v == find_v) return true;
    
    for (int i = 0; i < edges[v].size(); ++i) {
        if (*p_visited & (1 << edges[v][i])) continue;
        *p_visited |= (1 << edges[v][i]);
        if (dfs(edges[v][i], p_visited, find_v, edges)) return true;
    }

    return false;
}

void find(int start_v, int find_num, const vector<vector<int>>& edges) {
    int visited = (1 << start_v);

    if (dfs(start_v, &visited, find_num, edges)) {
        printf("found %d\n", find_num);
    }
    else {
        printf("not found %d\n", find_num);
    }
}

int main() {
    vector<vector<int>> edges = {{1, 2},
                                {0, 3},
                                {0, 4},
                                {1},
                                {2, 5},
                                {4},
                                {}};
    find(0, 3, edges);
    find(0, 6, edges);
}
