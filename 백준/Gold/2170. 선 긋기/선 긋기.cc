#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;





int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    pair<int, int> nowcheck;
    int accum = 0;
    int answer = 0;

    for(auto point : v) {
        int x = point.first;
        int y = point.second;

        if(accum == 0) {
            nowcheck = {x, y};
            accum++;
            continue;
        }

        int curx = nowcheck.first;
        int cury = nowcheck.second;

        if(x <= cury) {
            nowcheck = {curx, max(cury, y)};
            accum++;
            continue;
        }
        answer += cury - curx;
        nowcheck = {x, y};
        accum = 1;
    }

    answer += nowcheck.second - nowcheck.first;

    cout << answer;
    
    return 0;
}