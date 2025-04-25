#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> tree[32002];
int adj[32002];
queue<int> q;
vector<int> answer;


//위상 정렬 문제

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int input1, input2;
    for(int i = 0; i < m; i++) {
        cin >> input1 >> input2;
        tree[input1].push_back(input2); // input1이 input2보다 먼저와야한다는 정보 저장
        adj[input2]++; // input2의 indegree의 정보를 갱신
    }

    for(int i = 1; i <= n; i++) {
        if(!adj[i]) { // 선수조건이 없는 노드부터 queue에 집어넣음
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); // q에 있는 노드를하나씩 빼면서
        q.pop();
        for(auto nxt : tree[cur]) { // 그 노드가 뻗어 나간 모든 노드들의 연결을 끊음(선수조건 만족)
            if(!--adj[nxt]) {
                q.push(nxt); // 더이상 선수 조건이 없는 노드들을 q에 넣음(0이 되는 순간)
            }
        }
        answer.push_back(cur); // 정답 배열에 저장
    }
    for(auto ans : answer) {
        cout << ans << " ";
    }
    
    
    
    
    

    return 0;

}
