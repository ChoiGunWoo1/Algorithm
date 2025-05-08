#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    string p;
    string x;
    cin >> t;
    while(t--) {
        deque<int> q;
        cin >> p;
        cin >> n;
        cin >> x;
        bool iserror = false;
        string numbers = x.substr(1);
        string num = "";
        for(int i = 0; i < numbers.length(); i++) {
            if(numbers[i] == ',' || numbers[i] == ']') {
                if(num == "") {
                    continue;
                }
                int input = 0;
                int pow = 1;
                reverse(num.begin(), num.end());
                for(int j = 0; j < num.length(); j++) {
                    input += (num[j] - '0') * pow;
                    pow *= 10;
                }
                q.push_back(input);
                num = "";
                continue;
            }
            num += numbers[i];
        }
        int reversecnt = 0;
        for(int i = 0; i < p.length(); i++) {
            if(p[i] == 'R') {
                reversecnt++;
            }
            else if(p[i] == 'D') {
                if(q.empty()) {
                    iserror = true;
                    break;
                }
                if(reversecnt % 2 == 0) {
                    q.pop_front();
                }
                else {
                    q.pop_back();
                }
            }
        }
        if(iserror) {
            cout << "error" << '\n';
            continue;
        }
        if(reversecnt % 2 == 1) {
            reverse(q.begin(), q.end());
        }
        cout << "[";
        for(auto it = q.begin(); it != q.end(); it++) {
            cout << *it;
            if(it != q.end()-1) {
                cout << ",";
            }
        }
        cout << "]";
        cout << '\n';
    }

    return 0;
}
