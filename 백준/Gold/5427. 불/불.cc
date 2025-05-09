#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

char m[1002][1002];
int f[1002][1002];
int s[1002][1002];


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int w, h;
        cin >> w >> h;
        for(int i = 0; i < h; i++) {
            fill(f[i], f[i]+ w, -1);
            fill(s[i], s[i]+ w, -1);
        }
        queue<pair<int, int>> fq;
        queue<pair<int, int>> sq;
        for(int i = 0; i < h; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < w; j++) {
                m[i][j] = str[j];
                if(str[j] == '*') {
                    fq.push({i, j});
                    f[i][j] = 0;
                }
                if(str[j] == '@') {
                    sq.push({i, j});
                    s[i][j] = 0;
                }
            }
        }
        while(!fq.empty()) {
            int curx = fq.front().first;
            int cury = fq.front().second;
            fq.pop();
            for(int i = 0; i< 4; i++) {
                int nxtx = curx + dx[i];
                int nxty = cury + dy[i];
                if(nxtx < 0 || nxtx >= h || nxty < 0 || nxty >= w || m[nxtx][nxty] == '#') {
                    continue;
                }
                if(f[nxtx][nxty] >= 0 && f[nxtx][nxty] <= f[curx][cury] + 1) {
                    continue;
                }
                f[nxtx][nxty] = f[curx][cury] + 1;
                fq.push({nxtx, nxty});
            }
        }
        int answer = -1;
        while(!sq.empty()) {
            bool isfind = false;
            int curx = sq.front().first;
            int cury = sq.front().second;
            sq.pop();
            for(int i = 0; i < 4; i++) {
                int nxtx = curx + dx[i];
                int nxty = cury + dy[i];
                if(nxtx < 0 || nxtx >= h || nxty < 0 || nxty >= w) {
                    answer = s[curx][cury] + 1;
                    isfind = true;
                    break;
                }
                if(s[nxtx][nxty] >= 0 || (f[nxtx][nxty] >=0 && s[curx][cury] + 1 >= f[nxtx][nxty]) || m[nxtx][nxty] == '#') {
                    continue;
                }
                s[nxtx][nxty] = s[curx][cury] + 1;
                sq.push({nxtx, nxty});
            }
            if(isfind) {
                break;
            }
        }
        if(answer == -1) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << answer << '\n';
        }

    }
    
    


    return 0;
}
