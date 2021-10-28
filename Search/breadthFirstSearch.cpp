//----------------------------------------------------------------------------------
// [ BreadthFirstSearch ]
//
// 시간복잡도: O(V+E) 
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

bool bfs(int start_v, int find_num, const vector<vector<int>>& edges) {
    queue<int> q;
    int visited = (1 << start_v);

    if (start_v == find_num) return true;

    q.push(start_v);

    while (!q.empty()) {
        int v = q.front(); 
        q.pop();

        for (int i = 0; i < edges[v].size(); ++i) {
            if (edges[v][i] == find_num) return true;
            if (visited & (1 << edges[v][i])) continue;
            
            q.push(edges[v][i]);
            visited |= (1 << edges[v][i]);
        }
    }

    return false;
}

void find(int start_v, int find_num, const vector<vector<int>>& edges) {
    if (bfs(start_v, find_num, edges)) {
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
