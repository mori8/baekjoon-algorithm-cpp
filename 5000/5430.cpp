#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    bool reverse;
    bool empty;
    int t, n;
    cin >> t;
    while (t--) {
        string cmd = "";
        string arr = "";
        deque<int> dq;
        reverse = false;
        empty = false;

        cin >> cmd;
        cin >> n;
        cin >> arr;

        string num = "";
        for (int i = 0; i < arr.length(); i++) {
            if (arr[i] == ',' || arr[i] == ']') {
                if (arr[i-1] == '[')
                    break;
                dq.push_back(stoi(num));
                num = "";
            } else if (arr[i] != '[' && arr[i] != ']') {
                num += arr[i];
            }
        }
        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') {
                if (reverse) {
                    reverse = false;
                } else {
                    reverse = true;
                }
            } else if (cmd[i] == 'D') {
                if (dq.size() <= 0) {
                    empty = true;
                    break;
                }
                if (reverse) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }
        if (empty) {
            cout << "error" << endl;
        } else {
            cout << "[";
            while (!dq.empty()) {
                if (!reverse) {
                    cout << dq.front();
                    dq.pop_front();
                } else {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (!dq.empty()) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
    return 0;
}
