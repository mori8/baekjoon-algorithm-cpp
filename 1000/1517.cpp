#include <iostream>

using namespace std;

int arr[500001];
int tmp[500001];

long long solve(int s, int e) {
    if (s - e == 0) {
        return 0;
    }
    int mid = (s + e) / 2;
    long long cnt = solve(s, mid) + solve(mid + 1, e);

    int i = s;
    int j = mid + 1;
    int k = 0;

    while (i <= mid || j <= e) {
        // 반복문 한 개로 두 배열의 원소 모두 집어넣기
        if (i <= mid && (j > e || arr[i] <= arr[j])) {
            tmp[k++] = arr[i++];
        } else {
            cnt += (long long)(mid - i + 1);
            tmp[k++] = arr[j++];
        }
    }
    for (int u = s; u <= e; u++) {
        arr[u] = tmp[u - s];
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", solve(0, n-1));
    return 0;
}
