#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m; // 세로크기, 가로크기
int picture[501][501]; // 그림 정보 저장
bool visited[501][501] = { // 방문 여부 확인
    0,
};
int pnum = 0; // 그림의 개수
int maxwid = 0; // 최대 넓이

void solution()
{
//BFS사용 -> queue 이용
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;

    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < m; v++)
        {
            int w = 0;
            if (picture[u][v] == 1 && !visited[u][v]) // 아직 발견 못한 그림찾기
            {
                q.push(make_pair(u, v));
                pnum++; // 새 그림 발견했으므로 그림 조각 +1
                w++; // 그림의 크기 1 늘림
                visited[u][v] = true;
            }
            while (!q.empty()) // 그 그림 조각과 이어진 그림들을 전부 찾기
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    {
                        continue;
                    }
                    if (visited[nx][ny] || picture[nx][ny] != 1) {
                        continue;
                    }
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    w++; // 이어진 그림조각 찾을때마다 그림 넓이 갱신
                }
            }
            if(maxwid < w) {
                maxwid = w; // 발견된 그림 넓이가 최대 넓이이면 최대 넓이 갱신
            }
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> picture[i][j];
        }
    }
 
    solution();
    cout << pnum << '\n';
    cout << maxwid;

    return 0;
}