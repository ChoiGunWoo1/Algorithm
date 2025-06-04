#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define GREEN 3
#define RED 4
#define FLOWER 5

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, r, g;
int garden[52][52];

int answer = 0;

int check_flower() {
    int flower = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(garden[i][j] == FLOWER) {
                flower++;
            }
        }
    }
    return flower;
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r >> g;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> garden[i][j];
            if(garden[i][j] == 2) {
                v.push_back({i, j});
            }
        }
    }

    vector<int> brute;
    for(int i = 0; i < v.size() - (r+g); i++) {
        brute.push_back(0);
    }
    for(int i = 0; i < g; i++) {
        brute.push_back(GREEN);
    }
    for(int i = 0; i < r; i++) {
        brute.push_back(RED);
    }

    do {
        int beforgarden[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                beforgarden[i][j] = garden[i][j];
            }
        }

        pair<int, int> visited[n][m]; //<방문 시간, 방문 색깔>
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                visited[i][j] = {-1, -1};
            }
        }
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < v.size(); i++) {
            if(brute[i] == 0) {
                continue;
            }
            else if(brute[i] == GREEN) {
                q.push({v[i].first, v[i].second, GREEN});
                visited[v[i].first][v[i].second] = {0, GREEN};
                garden[v[i].first][v[i].second] = GREEN;
            }
            else if(brute[i] == RED) {
                q.push({v[i].first, v[i].second, RED});
                visited[v[i].first][v[i].second] = {0, RED};
                garden[v[i].first][v[i].second] = RED;
            }
        }
        while(!q.empty()) {
            int curx, cury, curcolor;
            tie(curx, cury, curcolor) = q.front();
            q.pop();
            if(garden[curx][cury] == FLOWER) {
                continue;
            }
            for(int i = 0; i < 4; i++) {
                int nxtx = curx + dx[i];
                int nxty = cury + dy[i];
                if(nxtx < 0 || nxty < 0 || nxtx >= n || nxty >= m) {
                    continue;
                }
                if(garden[nxtx][nxty] == 0) {
                    continue;
                }
                if(garden[nxtx][nxty] == FLOWER) {
                    continue;
                }
                if(visited[nxtx][nxty].first >= 0) {
                    if(visited[nxtx][nxty].first > visited[curx][cury].first + 1) {
                        visited[nxtx][nxty] = {visited[curx][cury].first + 1, curcolor};
                        garden[nxtx][nxty] = garden[curx][cury];
                        q.push({nxtx, nxty, curcolor});
                        continue;
                    }
                    else if(visited[nxtx][nxty].first < visited[curx][cury].first + 1) {
                        continue;
                    }
                    else if(visited[nxtx][nxty].first == visited[curx][cury].first + 1) {
                        if(visited[nxtx][nxty].second != curcolor && garden[nxtx][nxty] != FLOWER) {
                            garden[nxtx][nxty] = FLOWER;
                        }
                        continue;
                    }
                }
                visited[nxtx][nxty] = {visited[curx][cury].first + 1, curcolor};
                garden[nxtx][nxty] = garden[curx][cury];
                q.push({nxtx, nxty, curcolor});
            }
        }
        answer = max(answer, check_flower());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                garden[i][j] = beforgarden[i][j];
            }
        }
    } while(next_permutation(brute.begin(), brute.end()));
    
    cout << answer;

    return 0;
}
