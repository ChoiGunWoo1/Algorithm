#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>



using namespace std;

vector<int> graph[1002];
stack<int> s;
queue<int> q;

bool viss[1002];
bool visq[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;
    int v1, v2;
    while(m--) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

 // DFS
    s.push(start);
    while(!s.empty()) {
        int v = s.top();
        s.pop();
        if(viss[v]) {
            continue;
        }
        viss[v] = true;
        cout << v << " ";
        sort(graph[v].begin(), graph[v].end(), greater<int>());
        for(auto nxt = graph[v].begin(); nxt != graph[v].end(); nxt++) {
            s.push(*nxt);
        }
    }
    cout << "\n";
 // BFS
    q.push(start);
    visq[start] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        sort(graph[v].begin(), graph[v].end());
        for(auto nxt = graph[v].begin(); nxt != graph[v].end(); nxt++) {
            if(!visq[*nxt]) {
                q.push(*nxt);
                visq[*nxt] = true;
            }
        }
    }
    
    

    return 0;

}
