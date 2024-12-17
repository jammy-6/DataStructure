#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    /// 记录每个节点的入度
    vector<int> inDegrees(n, 0);
    unordered_map<int, vector<int>> mm;
    for (int i = 0; i < m; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        inDegrees[f2]++;
        mm[f1].push_back(f2);
    }

    /// 入度为零的队列
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegrees[i] == 0) {
            q.push_back(i);
        }
    }
    vector<int> ans;
    while (q.size() != 0) {
        // 出队并删除，并加入答案队列
        int front = q.front();
        q.pop_front();
        ans.push_back(front);

        // 减少其相连节点的入读，并寻找新的入度为零的节点入队
        vector<int> deps = mm[front];
        for (int i = 0; i < deps.size(); i++) {
            inDegrees[deps[i]]--;
            if (inDegrees[deps[i]] == 0) {
                q.push_back(deps[i]);
            }
        }
    }
    if (ans.size() < n) {
        cout << -1;
        return 0;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}