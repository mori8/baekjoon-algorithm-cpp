#include <iostream>

using namespace std;

int paper[4097][4097];

// (x, y) ~ (x + m - 1, y + m - 1)까지의 수가 모두 같은지 확인
bool check(int x, int y, int m) {
    int checkInt = paper[x][y];
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            if (checkInt != paper[i][j]) return false;
        }
    }
    printf("%d", paper[x][y]);
    return true;
}

// (x, y) ~ (x + m - 1, y + m - 1)까지의 수가 종이 규칙을 만족하는지 확인
void solve(int x, int y, int m) {
    if (check(x, y, m)) {
        ;
    } else {
        printf("(");
        int k = m / 2;
        solve(x, y, k);
        solve(x, y + k, k);
        solve(x + k, y, k);
        solve(x + k, y + k, k);
        printf(")");
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &paper[i][j]);
        }
    }
    solve(0, 0, n);
    return 0;
}
