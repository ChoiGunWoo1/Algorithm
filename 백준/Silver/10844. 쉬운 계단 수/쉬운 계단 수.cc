#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000000

using namespace std;

ll dp[10][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            dp[i][1] = 0;
        }
        else {
            dp[i][1] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) {
                dp[1][i+1] = (dp[1][i+1] + dp[j][i]) % MOD;
            }
            else if(j == 9) {
                dp[8][i+1] = (dp[8][i+1] + dp[j][i]) % MOD;
            }
            else {
                dp[j-1][i+1] = (dp[j-1][i+1] + dp[j][i]) % MOD;
                dp[j+1][i+1] = (dp[j+1][i+1] + dp[j][i]) % MOD;
            }
        }
    }

    ll answer = 0;
    for(int i = 0; i < 10; i++) {
        answer += dp[i][n];
    }

    answer %= MOD;

    cout << answer;
    
    
    return 0;
}