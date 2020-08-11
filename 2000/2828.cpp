#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    int left = 1;
    int right = m;
    int move = 0;

    int j;
    cin >> j;
    int apple;

    for (int i = 0; i < j; i++) {
        cin >> apple;
        // 움직이지 않아도 사과를 받을 수 있을 때
        if (apple <= right && apple >= left) {
            continue;
        }
        // 바구니 왼쪽에 사과가 떨어지는 경우
        if (apple < left) {
            move += left - apple;
            left = apple;
            right = left + m - 1;
        } else if (apple > right) { // 바구니 오른쪽에 사과가 떨어지는 경우
            move += apple - right;
            right = apple;
            left = right - m + 1;
        }
    }
    cout << move;
    return 0;
}
