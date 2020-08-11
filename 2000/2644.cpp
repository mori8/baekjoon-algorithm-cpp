#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[101] = {false, };
int chon[101] = {-1, };

vector<int> tree[10500];


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    queue<int> q;

    visit[x] = true;
    q.push(x);
    int next = -1;
    do {
        int node = q.front();
        q.pop();
        for (int i = 0; i < tree[node].size(); i++) {
            next = tree[node][i];
            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
                chon[next] = chon[node] + 1;
            }
        }
    } while (next != y && !q.empty());
    if (chon[y] == 0) {
        chon[y] = -1;
    }
    cout << chon[y];
}
