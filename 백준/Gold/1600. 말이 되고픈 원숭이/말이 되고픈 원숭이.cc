#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;


int m[202][202];
int r[202][202][32];
int dx[12] = {1, -1, 0, 0, 2, 2, -2, -2, 1, 1, -1, -1};
int dy[12] = {0, 0, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, w, h;
    cin >> k >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> m[i][j];
            fill(r[i][j], r[i][j] + k+1, -1);
        }
    }

    queue<tuple<int, int, int>> q; // x, y, 남은 k
    q.push({0, 0, k});
    r[0][0][k] = 0;
    while(!q.empty()) {
        int curx, cury, leftk;
        tie(curx, cury, leftk) = q.front();
        q.pop();
        int index;
        if(leftk > 0) {
            index = 12;
        }
        else {
            index = 4;
        }
        for(int i = 0; i < index; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            if(nxtx < 0 || nxtx >= h || nxty < 0 || nxty >= w) {
                continue;
            }
            if(m[nxtx][nxty] == 1) {
                continue;
            }
            if(i < 4) {
                if(r[nxtx][nxty][leftk] < 0) {
                    r[nxtx][nxty][leftk] = r[curx][cury][leftk] + 1;
                    q.push({nxtx, nxty, leftk});
                    continue;
                }
                continue;
            }
            if(r[nxtx][nxty][leftk-1] < 0) {
                r[nxtx][nxty][leftk-1] = r[curx][cury][leftk] + 1;
                q.push({nxtx, nxty, leftk-1});
                continue;
            }
        }

    }
    int answer = 0x7f7f7f7f;
    for(int i = 0; i <= k; i++) {
        if(r[h-1][w-1][i] >= 0) {
            answer = min(answer, r[h-1][w-1][i]);
        }
    }
    if(answer == 0x7f7f7f7f) {
        cout << -1;
    }
    else {
        cout << answer;
    }


    return 0;
}
