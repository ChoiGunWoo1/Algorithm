#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> tree[100002];
int parent[100002];
queue<int> q;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int v1, v2;
    for(int i = 0; i < n-1; i++) {
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    //DFS 활용
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto nxt = tree[cur].begin(); nxt != tree[cur].end(); nxt++) {
            if(*nxt == parent[cur]) {
                continue;
            }
            q.push(*nxt);
            parent[*nxt] = cur;
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    
    
    

    return 0;

}
