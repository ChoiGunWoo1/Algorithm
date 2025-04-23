#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



using namespace std;

vector<int> graph[1002];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int v1, v2;
    while(m--) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    queue<int> q;
    bool visited[1002] = {0, };
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) {
            continue;
        }
        answer++;
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto e = graph[v].begin(); e != graph[v].end(); e++) {
                if(!visited[*e]) {
                    q.push(*e);
                    visited[*e] = true;
                }
            }
        }
    }
    cout << answer;
    
    

    return 0;

}
