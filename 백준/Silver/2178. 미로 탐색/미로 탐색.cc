#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool visited[101][101];
int maze[101][101];

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

queue<pair<pair<int, int>, int>> q;

int N, M;
int ans = 0;

int bfs(int i, int j)
{
    visited[i][j] = true;
    q.push(make_pair(make_pair(i, j), 1));
    while(!q.empty()) {
        int mx = q.front().first.first;
        int my = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(mx == N-1 && my == M-1) {
            ans = cnt;
        }
        for(int k = 0; k < 4; k++) {
            int nx = mx + x[k];
            int ny = my + y[k];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && maze[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), cnt+1));
            }
        }
    }
    return ans;
    
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    cin >> N >> M;
    string input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        for(int j = 0; j < M; j++) {
            maze[i][j] = input[j] - '0';
        }
    }
    cout << bfs(0, 0);


    return 0;
}