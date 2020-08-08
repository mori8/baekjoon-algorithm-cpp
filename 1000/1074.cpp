#include <iostream>

using namespace std;

int pow(int k) {
    return (1 << k);
}

int solve(int n, int x, int y) {
    if (n == 1) {
        return 2*x + y;
    } else {
        if (x < pow(n - 1)) {
            if (y < pow(n - 1)) {  // 제1사분면
                return solve(n-1, x, y);
            } else {  // 제2사분면
                return solve(n-1, x, y - pow(n-1)) + pow(2*(n-1));
            }
        } else {
            if (y < pow(n - 1)) {  // 제3사분면
                return solve(n-1, x - pow(n-1), y) + pow(2*(n-1)) * 2;
            } else {  // 제4사분면
                return solve(n-1, x - pow(n-1), y - pow(n-1)) + pow(2*(n-1)) * 3;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, r, c;
    cin >> n >> r >> c;

    cout <<solve(n, r, c);
    return 0;
}
