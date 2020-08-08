#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[1050] = {false, };
vector<int> tree[1050];

void dfs(int x) {
    visit[x] = true;
    cout << x << " ";
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];
        if (!visit[next]) {
            dfs(next);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    visit[x] = true;
    q.push(x);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i];
            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    int v, e, n;

    cin >> v >> e >> n;
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    for (int i = 1; i <= v; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    dfs(n);
    cout << "\n";
    memset(visit, false, sizeof(visit));
    bfs(n);
    return 0;
}
