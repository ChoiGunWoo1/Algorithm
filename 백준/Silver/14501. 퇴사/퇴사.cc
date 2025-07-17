#include <iostream>
#include <algorithm>

using namespace std;

int T[17]; // 상담에 걸리는 기간
int P[17]; // 상담 했을때 받을 수 있는 금액
int dp[17]; // dp[n] : n일 전까지 받을 수 있는 최대 금액

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
        cin >> P[i];
    }

    for(int i = 1; i <= n+1; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        int after = i + T[i];
        if(after >= n+2) {
            continue;
        }
        dp[after] = max(dp[after], dp[i] + P[i]);
    }
    cout << dp[n+1];
    
    return 0;
}