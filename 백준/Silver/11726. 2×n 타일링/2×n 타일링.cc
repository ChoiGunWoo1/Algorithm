#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int N;

long long dp[1002][2];
//dp[i][0] : i번째 직사각형까지 채우는 방법, 단, 직사각형이 가로여야함
//dp[i][1] : i번째 직사각형까지 채우는 방법, 단, 직사각형이 세로여야함

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < N; i++) {
        dp[i][0] = (dp[i-2][0] % 10007) + (dp[i-2][1] % 10007);
        dp[i][1] = (dp[i-1][0] % 10007) + (dp[i-1][1] % 10007);
    }
    long long answer = (dp[N-1][0] + dp[N-1][1]) % 10007;
    cout << answer;
    


    
    
    
    return 0;
}