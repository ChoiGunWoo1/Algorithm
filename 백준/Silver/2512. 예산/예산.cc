#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

bool Check(int x) {
    int sum = 0;
    int mm = -1;
    for(auto money : v) {
        mm = max(money, mm);
        if(money <= x) {
            sum += money;
        }
        else {
            sum += x;
        }
    }

    if(sum <= m && x <= mm)  {
        return true;
    }
    else {
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    cin >> m;

    sort(v.begin(), v.end());

    int st = 1;
    int en = m;
    int answer = -1;

    while(st <= en) {
        int mid = (st + en) / 2;

        if(Check(mid)) {
            answer = mid;
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
        
    }

    cout << answer;

    return 0;
}