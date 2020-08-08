#include <iostream>

using namespace std;

int paper[2188][2188];
int counts[3] = {0, };

// (x, y) ~ (x + m - 1, y + m - 1)까지의 수가 모두 같은지 확인
bool check(int x, int y, int m) {
    int checkInt = paper[x][y];
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            if (checkInt != paper[i][j]) return false;
        }
    }
    counts[checkInt + 1]++;
    return true;
}

// (x, y) ~ (x + m - 1, y + m - 1)까지의 수가 종이 규칙을 만족하는지 확인
void solve(int x, int y, int m) {
    if (check(x, y, m)) {
        return;
    } else {
        int k = m / 3;
        solve(x, y, k);
        solve(x, y + k, k);
        solve(x, y + 2*k, k);
        solve(x + k, y, k);
        solve(x + k, y + k, k);
        solve(x + k, y + 2*k, k);
        solve(x + 2*k, y, k);
        solve(x + 2*k, y + k, k);
        solve(x + 2*k, y + 2*k, k);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", counts[i]);
    }
    return 0;
}
