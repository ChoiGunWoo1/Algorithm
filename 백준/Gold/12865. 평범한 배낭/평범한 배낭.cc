#include <iostream>
#include <algorithm>


using namespace std;

int dp[102][100002];
pair<int, int> stuff[101];
//dp[i][j] = i번째 까지 물건을 선택할 수 있고 최대 무게는 j일때 최대 가치

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, w, v;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        stuff[i] = make_pair(w, v); // 무게, 가치 순으로 저장
    }
    for(int i = 0; i < n; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(stuff[i-1].first > j) { // 현재 가방에 넣을 물건 무게보다 최대 무게가 작을 경우 -> 이 물건을 넣기전의 최대 가치를 그대로 넣는다
                dp[i][j] = dp[i-1][j]; // 한마디로, 물건을 넣지 않는다.
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-stuff[i-1].first] + stuff[i-1].second); // 현재 선택한 물건을 담을 수 있는 최대 크기라면, 넣었을 때랑 넣지 않았을 때 가치를 비교한다                
            }
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer;

    return 0;
}