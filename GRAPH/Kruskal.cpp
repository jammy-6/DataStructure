#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parent[10010];

/// @brief 并查集初始化算法
void init() {
    for (int i = 0; i < 10010; i++)
        parent[i] = i;
}

int find(int u) { return u == parent[u] ? u : parent[u] = find(parent[u]); }

bool isSame(int u, int v) { return find(u) == find(v); }

void join(int u, int v) {
    int up = find(u);
    int uv = find(v);
    if (up == uv)
        return;
    else
        parent[uv] = up;
}

typedef struct Edge {
    int u, v, val;
} Edge;

int main() {
    int nv, ne;

    cin >> nv >> ne;
    vector<Edge> path;
    vector<Edge> data(ne, {0, 0, 0});
    for (int i = 0; i < ne; i++) {
        cin >> data[i].u >> data[i].v >> data[i].val;
    }
    int ans = 0;
    sort(data.begin(), data.end(),
         [](const Edge &e1, const Edge &e2) { return e1.val < e2.val; });
    init();
    /// 遍历每一条边，如果两端节点不在同一个集合，则计入
    for (int i = 0; i < ne; i++) {
        if (isSame(data[i].u, data[i].v)) {
            continue;
        } else {
            join(data[i].u, data[i].v);
            path.push_back(data[i]);
            ans += data[i].val;
        }
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i].u << ":" << path[i].v << endl;
    }
    cout << ans;

    return 0;
}