#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d\n", &n);

    char arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }
    int can_lie_c = 0;

    for (int i = 0; i < n; i++) {
        int size = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'X') {
                if (size >= 2) {
                    can_lie_c++;
                }
                size = 0;
            } else {
                size++;
            }
        }
        if (size >= 2) {
            can_lie_c++;
            size = 0;
        }
    }
    int can_lie_r = 0;
    for (int i = 0; i < n; i++) {
        int size = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 'X') {
                if (size >= 2) {
                    can_lie_r++;
                }
                size = 0;
            } else {
                size++;
            }
        }
        if (size >= 2) {
            can_lie_r++;
        }
    }
    printf("%d %d", can_lie_c, can_lie_r);
    return 0;
}
