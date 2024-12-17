#include <iostream>
#include <vector>
using namespace std;

/// 输入
// 7 3
// 2 3 4
// 3 6 6
// 4 7 8
// 2
// 2 3
// 3 4

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT32_MAX));

    for (int i = 0; i < m; i++) {
        int s, e, val;
        cin >> s >> e >> val;
        /// 双向图
        grid[s][e] = val;
        grid[e][s] = val;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j] =
                    min((unsigned long long int)grid[i][j],
                        (unsigned long long int)grid[i][k] + grid[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        if (grid[s][e] != INT32_MAX)
            cout << grid[s][e] << endl;
        else
            cout << -1 << endl;
    }
}