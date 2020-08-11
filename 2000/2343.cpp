#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long int sum;
int arr[1000001];



long long int b_search(long long int left, long long int right) {
    long long int mid;
    long long int ans = 9999999999;
    while (left <= right) {
        mid = (left + right) / 2;
        int idx = 0;
        int cnt = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
           if (sum + arr[i] > mid) {
              cnt++;
              sum = 0;
           }
           sum += arr[i];
        }
        cnt++;
        if (cnt > m) {
            left = mid + 1;
        } else {
            ans = min(ans, mid);
            right = mid - 1;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%llu", b_search(*max_element(arr, arr + n), sum));
    return 0;
}
