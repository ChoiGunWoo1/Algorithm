#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int rx, ry, bx, by, depth;
};

int n, m;

char board[12][12];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


bool tilt(int &x, int &y, int dir, int &cnt) {
    cnt = 0;
    while(true) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        if(board[nx][ny] == '#') {
            break;
        }
        x = nx; y = ny; cnt++;
        if(board[nx][ny] == 'O') {
            return true;
        }
    }
    return false;
}

int BFS(pair<int, int> red, pair<int, int> blue) {
    bool visited[12][12][12][12] = {0};
    queue<Node> q;
    q.push({red.first, red.second, blue.first, blue.second, 0});
    visited[red.first][red.second][blue.first][blue.second] = true;

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int rx = cur.rx; int ry = cur.ry; int bx = cur.bx; int by = cur.by; int depth = cur.depth;
            int bcnt = 0;
            int rcnt = 0;

            if(depth == 10) {
                continue;
            }

            if(tilt(bx, by, i, bcnt)) {
                continue;
            }
            if(tilt(rx, ry, i, rcnt)) {
                return depth + 1;
            }

            if(rx == bx && ry == by) {
                if(bcnt > rcnt) {bx -= dx[i]; by -= dy[i];}
                else {rx -= dx[i]; ry -= dy[i];}
            }

            if(visited[rx][ry][bx][by]) {
                continue;
            }

            visited[rx][ry][bx][by] = true;
            q.push({rx, ry, bx, by, depth+1});
        }
    }
    return -1;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    pair<int, int> red; pair<int, int> blue;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                red = {i, j};
            }
            else if(board[i][j] == 'B') {
                blue = {i, j};
            }
        }
    }

    int answer = BFS(red, blue);

    cout << answer;


    
    return 0;
}