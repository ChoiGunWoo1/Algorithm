#include <iostream>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int _map[1002][1002];
int route[1002][1002];
queue<pair<int, int>> rq;
queue<pair<int, int>> wq;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void printing(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << route[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            _map[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        fill(route[i], route[i] + m, -1);
    }
    rq.push({0,0});
    route[0][0] = 0;
    while(!rq.empty()) {
        int curx = rq.front().first;
        int cury = rq.front().second;
        rq.pop();
        for(int i = 0; i < 4; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) {
                continue;
            }
            if(route[nxtx][nxty] >= 0) {
                continue;
            }
            if(_map[nxtx][nxty] == 1) {
                route[nxtx][nxty] = route[curx][cury] + 1;
                wq.push({nxtx, nxty});
                continue;
            }
            route[nxtx][nxty] = route[curx][cury] + 1;
            rq.push({nxtx, nxty});
        }
    }
    while(!wq.empty()) {
        int curx = wq.front().first;
        int cury = wq.front().second;
        wq.pop();
        for(int i = 0; i < 4; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            if(nxtx < 0 || nxtx > n || nxty < 0 || nxty > m) {
                continue;
            }
            if(_map[nxtx][nxty] == 1) {
                continue;
            }
            if(route[nxtx][nxty] >= 0) {
                if(route[nxtx][nxty] > route[curx][cury] + 1) {
                    route[nxtx][nxty] = route[curx][cury] + 1;
                    wq.push({nxtx, nxty});
                }
                continue;
            }
            route[nxtx][nxty] = route[curx][cury] + 1;
            wq.push({nxtx, nxty});
        }
    }
    if(route[n-1][m-1] == -1) {
        cout << -1;
    }
    else {
        cout << route[n-1][m-1] + 1;
    }

    
    
    


    return 0;
}
