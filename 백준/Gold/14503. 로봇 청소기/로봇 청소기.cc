#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int room[52][52];
int dir[52][52];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

void cleaning(int x, int y, int d) {
    queue<tuple<int, int, int>> q;
    room[x][y] = 2;
    q.push({x, y, d});

    while(!q.empty()) {
        int curx, cury, curdir;
        tie(curx, cury, curdir) = q.front();
        q.pop();

        bool isnocleaning = false;

        for(int i = 0; i < 4; i++) {
            int checkx = curx + dx[i];
            int checky = cury + dy[i];

            if(room[checkx][checky] == 0) {
                isnocleaning = true;
                break;
            }
        }

        if(!isnocleaning) {
            int nxtx = curx; int nxty = cury;
            if(curdir == 0) { nxtx += 1;}
            else if(curdir == 1) { nxty -= 1;}
            else if(curdir == 2) { nxtx -= 1;}
            else { nxty += 1;}

            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) {
                return;
            }
            if(room[nxtx][nxty] == 1) {
                return;
            }
            q.push({nxtx, nxty, curdir});
            continue;
        }

        int nxtdir = curdir;

        for(int i = 0; i < 4; i++) {
            nxtdir = (nxtdir + 3) % 4;
            
            int nxtx = curx; int nxty = cury;

            if(nxtdir == 0) { nxtx -= 1; }
            else if(nxtdir == 1) { nxty += 1; }
            else if(nxtdir == 2) { nxtx += 1; }
            else if(nxtdir == 3) { nxty -= 1; }

            if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) {
                continue;
            }
            if(room[nxtx][nxty] == 1 || room[nxtx][nxty] == 2) {
                continue;
            }
            if(room[nxtx][nxty] == 0) {
                room[nxtx][nxty] = 2;
                q.push({nxtx, nxty, nxtdir});
                break;
            }
        }  
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int x, y, d;
    cin >> x >> y >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    cleaning(x, y, d);

    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(room[i][j] == 2) {
                answer++;
            }
        }
    }

    cout << answer;
    
    
    return 0;
}