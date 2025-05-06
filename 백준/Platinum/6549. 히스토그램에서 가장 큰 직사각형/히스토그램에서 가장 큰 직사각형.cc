#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = -1;
    while (true)
    {
        cin >> n;
        if(n == 0) {
            break;
        }
        stack<pair<ll, ll>> st; // {i, j} : i번째 직사각형의 크기는 j
        ll answer = 0;
        for (int i = 1; i <= n; i++)
        {
            int input;
            cin >> input;
            if (st.empty())
            {
                st.push({i, input});
                continue;
            }
            if (st.top().second <= input)
            {
                st.push({i, input});
                continue;
            }
            ll idx;
            while (!st.empty() && st.top().second > input)
            {
                idx = st.top().first;
                ll nowmax = st.top().second * (i - idx);
                answer = max(answer, nowmax);
                st.pop();
            }
            st.push({idx, input});
        }
        while (!st.empty())
        {
            ll idx = st.top().first;
            ll nowmax = st.top().second * (n + 1 - idx);
            answer = max(answer, nowmax);
            st.pop();
        }
        cout << answer << '\n';
    }

    return 0;
}
