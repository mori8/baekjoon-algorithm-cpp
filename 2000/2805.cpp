#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int m;
int tree[1000001];

bool check(int x) {
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i] >= x)
            s += tree[i] - x;
    }
    if (s >= m) return true;
    return false;
}

int b_search(int left, int right) {
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    scanf("%d %llu", &n, &m);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        if (maxx < tree[i]) maxx = tree[i];
    }
    printf("%d", b_search(1, maxx));
    return 0;
}
