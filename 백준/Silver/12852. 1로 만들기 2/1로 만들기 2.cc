#include <iostream>
#include <algorithm>
#define Maxn 1000002

using namespace std;

int N;

pair<int, int> dp[Maxn];
//첫번째 숫자 : 그 숫자에 도달하기 위한 최소 연산 수
//두번째 숫자 : 그 숫자에 도달하기 위한 최소 연산과정의 바로 전 수


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        if(i == 1) {
            dp[i] = make_pair(0, 0);
            continue;
        }
        dp[i] = make_pair(Maxn, Maxn);
    }
    for(int i = 1; i <= N-1; i++) {
        int num = dp[i].first + 1;
        if(i + 1 <= N) {
            int one = dp[i+1].first;
            if(one > num) {
                dp[i+1] = make_pair(num, i);
            }
        }
        if(i * 2 <= N) {
            int two = dp[i*2].first;
            if(two > num) {
                dp[i*2] = make_pair(num, i);
            }
        }
        if(i * 3 <= N) {
            int three = dp[i*3].first;
            if(three > num) {
                dp[i*3] = make_pair(num, i);
            }
        }
    }
    cout << dp[N].first << '\n';
    int answer = dp[N].second;
    cout << N << " ";
    while(answer != 0) {
        cout << answer << " ";
        answer = dp[answer].second;
    }
    
    
    


    
    
    
    return 0;
}