#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, z, m, tmp, pos;
    scanf("%d %d %d\n", &n ,&z, &m);
    int map[n];
    memset(map, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        map[tmp-1] = 1;
    }
    if (m == 0) {
        printf("1\n");
        exit(0);
    }
    for (int i = 1; i <= z; i++) {
        pos = 0;
        while (1) {
            pos += i;
            pos %= n;
            if (pos == 0 || map[pos] == 1) break;
            if (pos == z-1) {
                printf("%d\n", i);
                exit(0);
            }
        }
    }
}
