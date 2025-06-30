#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int lab[10][10];

int beforelab[10][10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];

            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) {
                continue;
            }
            if(beforelab[nxtx][nxty] == 2 || beforelab[nxtx][nxty] == 1) {
                continue;
            }
            beforelab[nxtx][nxty] = 2;
            q.push({nxtx, nxty});
        }
    }

}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    vector<int> comb;

    int combnum = 0;

    int safezone = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == 0) {
                v1.push_back({i, j});
                combnum++;
            }
            else if(lab[i][j] == 2) {
                v2.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < combnum - 3; i++) {
        comb.push_back(0);
    }
    for(int i = 0; i < 3; i++) {
        comb.push_back(1);
    }

    do {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                beforelab[i][j] = lab[i][j];
            }
        }
        for(int i = 0; i < combnum; i++) {
            if(comb[i]) {
                beforelab[v1[i].first][v1[i].second] = 1;
            }
        }

        for(auto pos : v2) {
            BFS(pos.first, pos.second);
        }

        int safe = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(beforelab[i][j] == 0) {
                    safe++;
                }
            }
        }

        safezone = max(safezone, safe);
        
    } while(next_permutation(comb.begin(), comb.end()));

    cout << safezone;
    
    return 0;
}