#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m, tmp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    cin >> m;
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        int check = binary_search(v.begin(), v.end(), tmp);
        printf("%d\n", check);
    }
    return 0;
}
