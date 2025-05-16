#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int n;

int answer = 10002;

int island[102][102];
int bridge[102][102];
bool visited_island[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void set_island(int x, int y, int island_num) {
    queue<pair<int, int>> q;
    visited_island[x][y] = true;
    island[x][y] = island_num;
    q.push({x, y});
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= n) {
                continue;
            }
            if(visited_island[nxtx][nxty]) {
                continue;
            }
            if(island[nxtx][nxty] == 0) {
                continue;
            }
            visited_island[nxtx][nxty] = true;
            island[nxtx][nxty] = island_num;
            q.push({nxtx, nxty});
        }
    }

}

void bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    bridge[x][y] = 0;
    visited_island[x][y] = true;
    int island_num = island[x][y];
    q.push({x, y, 0});
    while(!q.empty()) {
        int curx, cury, length;
        tie(curx, cury, length) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= n) {
                continue;
            }
            if(visited_island[nxtx][nxty]) {
                continue;
            }
            if(bridge[nxtx][nxty] == -1) {
                if(island[nxtx][nxty] == island_num) {
                    bridge[nxtx][nxty] = 0;
                    q.push({nxtx, nxty, 0});
                    visited_island[nxtx][nxty] = true;
                    continue;
                }
                if(island[nxtx][nxty] == 0){
                    bridge[nxtx][nxty] = length + 1;
                    q.push({nxtx, nxty, length+1});
                    continue;
                }
                answer = min(answer, length);
                continue;
            }
            if(bridge[nxtx][nxty] > length + 1) {
                bridge[nxtx][nxty] = length + 1;
                q.push({nxtx, nxty, length+1});
                continue;
            }
        }
    }
}

void find_with_sea() {
    for(int i = 0; i < n; i++) {
        fill(visited_island[i], visited_island[i] + n, false);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(island[i][j] != 0 && !visited_island[i][j]) {
                for(int i = 0; i < n; i++) {
                    fill(bridge[i], bridge[i] + n, -1);
                }
                bfs(i, j);
            }
        }
    }
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> island[i][j];
        }
    }
    int inum = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(island[i][j] == 1 && !visited_island[i][j]) {
                set_island(i, j, inum);
                inum += 1;
            }
        }
    }
    
    find_with_sea();
    cout << answer;    


    return 0;
}
