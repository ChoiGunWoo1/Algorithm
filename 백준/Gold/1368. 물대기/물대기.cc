#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<pair<int, int>> connect_cost[302]; // connect_cost[v1] = {cost, v2};
bool intree[302];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
// 프림 알고리즘을 위한 우선순위 큐 구현

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, w;
    cin >> n;
    for(int i = 0; i < n; i++) { // 우물을 직접 파는 비용을 하나의 정점과 간선으로 두고 그래프에 추가
        cin >> w;
        connect_cost[n].push_back({w, i});
        connect_cost[i].push_back({w, n});
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w;
            connect_cost[i].push_back({w, j});
        }
    } 
    // 그 후 최소 신장 트리를 구하는 알고리즘을 쓰면 자동으로 우물을 파는 것까지 포함한 최소 비용이 나오게 된다.
    // 시작점은 0번째 논으로 잡음
    intree[0] = true;
    int cnt = 0;
    for(auto nxt : connect_cost[0]) {
        pq.push({nxt.first, 0, nxt.second});
    }
    int answer = 0;
    while(cnt < n) { // 프림 알고리즘 사용
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if(intree[v2]) {
            continue;
        }
        intree[v2] = true;
        answer += cost;
        cnt++;
        for(auto nxt : connect_cost[v2]) {
            pq.push({nxt.first, v2, nxt.second});
        }
        
    }
    
    cout << answer;


    
    
    
    

    return 0;

}
