#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int maze[5][5][5];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

vector<int> v[5];

void rotate(int i) {
    int before[5][5];
    for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
            before[j][k] = maze[i][j][k];
        }
    }

    int after[5][5];

    for(int k = 0; k < 5; k++) {
        for(int l = 0; l < 5; l++) {
            after[l][4-k] = before[k][l];
        }
    }

    for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
            maze[i][j][k] = after[j][k];
        }
    }

}

int bfs() {
    queue<tuple<int, int, int>> q;

    int visited[5][5][5];

    if(maze[0][0][0] == 0) {
        return -1;
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            fill(visited[i][j], visited[i][j] + 5, -1);
        }
    }

    visited[0][0][0] = 0;
    q.push({0, 0, 0});
    while(!q.empty()) {
        int curx, cury, curz;
        tie(curx, cury, curz) = q.front();
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nxtx = curx + dx[i];
            int nxty = cury + dy[i];
            int nxtz = curz + dz[i];

            if(nxtx < 0 || nxtx >= 5 || nxty < 0 || nxty >= 5 || nxtz < 0 || nxtz >= 5) {
                continue;
            }
            if(maze[nxtx][nxty][nxtz] == 0) {
                continue;
            }
            if(visited[nxtx][nxty][nxtz] >= 0) {
                continue;
            }
            
            visited[nxtx][nxty][nxtz] = visited[curx][cury][curz] + 1;
            q.push({nxtx, nxty, nxtz});
        }
    }

    return visited[4][4][4];

}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 25; j++) {
            int input;
            cin >> input;

            v[i].push_back(input);
        }
    }

    int cb[5] = {0, 1, 2, 3, 4};
    int answer = -1;

    do {
        int rnum = 4 * 4 * 4 * 4 * 4;

        for(int n = 0; n < rnum; n++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        maze[i][j][k] = v[cb[i]][j * 5 + k];
                    }
                }
            }
            int now = n;
            for(int i = 0; i < 5; i++) {
                int r = now % 4;
                now = now / 4;
                
                for(int j = 0; j < r; j++) {
                    rotate(i);
                }
            }
            int a = bfs();
            if(a == -1) {
                continue;
            }
            else {
                if(answer == -1) {
                    answer = a;
                }
                else {
                    answer = min(answer, a);
                }
            }
        }
    } while(next_permutation(cb, cb+5));

    cout << answer;
    
    
    
    return 0;
}