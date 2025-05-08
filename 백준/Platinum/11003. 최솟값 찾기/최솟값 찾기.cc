#include <iostream>
#include <algorithm>

#include <deque>

using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<pair<int,int>> d; // {i, j} : i번째 값은 j
    int n, l;
    cin >> n >> l;
    for(int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        while(!d.empty()) {
            if(input < d.back().second) {
                d.pop_back();
            }
            else {
                break;
            }
        }
        d.push_back({i, input});
        cout << d.front().second << " ";
        if(d.front().first <= i-l+1) {
            d.pop_front();
        }
    }
   

    return 0;
}
