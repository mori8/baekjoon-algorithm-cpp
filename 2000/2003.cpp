#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<int> q;
    int arr[10000];
    int n, cnt = 0;
    long long m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        q.push(arr[i]);
        while (sum > m) {
            if (!q.empty()) {
                sum -= q.front();
                q.pop();
            } else break;
        }
        if (sum == m) cnt++;
    }
    cout << cnt;
    return 0;
}
