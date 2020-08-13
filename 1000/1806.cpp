//
//  main.cpp
//  saupc_Team
//
//  Created by Suyeon Nam on 2020/08/12.
//  Copyright © 2020 Suyeon Nam. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<int> q;
    int min_length = 654321;
    int arr[100000];
    int n = 0, cnt = 0;
    long long m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        q.push(arr[i]);
        while (!q.empty() && sum - q.front() >= m) {
            sum -= q.front();
            q.pop();
        }
        if (sum >= m) {
            min_length = min(min_length, (int)q.size());
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    cout << min_length;
    return 0;
}
