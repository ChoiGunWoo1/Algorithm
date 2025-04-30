#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



using namespace std;

vector<pair<int, int>> bus[1002]; // bus[v1] = {cost, v2};

int min_cost[1002];
int pre[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 다익스트라 알고리즘을 위한 우선순위 큐 선언
    // pair{cost, v}가 저장됨
    const int INF = 1e9 + 10;
    int n, m;
    cin >> n >> m;
    int depart;
    int dest;
    for(int i = 0; i < m; i++) {
        int w, v1, v2;
        cin >> v1 >> v2 >> w;
        bus[v1].push_back({w, v2});
    }
    cin >> depart;
    cin >> dest;
    fill(min_cost, min_cost+1002, INF);
    //다익스트라 알고리즘 사용
    //첫 pq에 시작지점과 비용 0을 대입
    min_cost[depart] = 0;
    pq.push({min_cost[depart], depart});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(min_cost[cur.second] != cur.first) {
            continue;
        }// 갱신된 값이 아니면 반영하지 않음
        for(auto nxt : bus[cur.second]) {
            if(min_cost[cur.second] + nxt.first >= min_cost[nxt.second]) {
                continue;
            } 
            //만약 cur을 지나가는게 더 짧은 경로라면 갱신
            min_cost[nxt.second] = min_cost[cur.second] + nxt.first;
            pre[nxt.second] = cur.second;
            //pre배열에 이전 방문 노드 정보를 저장
            pq.push({min_cost[nxt.second], nxt.second});
        }
    }
    //pre배열을 참조하며 경로를 복원
    vector<int> answer;
    int city = dest;
    while(city != depart) {
        answer.push_back(city);
        city = pre[city];
    }
    answer.push_back(city);
    cout << min_cost[dest] << '\n';
    cout << answer.size() << '\n';
    for(auto nxt = answer.end()-1; nxt >= answer.begin(); nxt--) {
        cout << *nxt << " ";
    }
    
    return 0;

}
