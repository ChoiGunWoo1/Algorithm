#include <iostream>
#include <algorithm>
#include <queue>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3


using namespace std;

int board[102][102];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int returndir(int dir, char c) {
    int answer;
    if(c == 'L') {
        answer = (dir + 3) % 4;
    }
    else if(c == 'D') {
        answer = (dir + 1) % 4;
    }

    return answer;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int k;

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }

    int answer = 0;

    queue<pair<int, char>> q;
    deque<pair<int, int>> dq;

    board[0][0] = 2;

    int lasttime = 0; int nowx = 0; int nowy = 0; int nowdir = RIGHT;
    dq.push_front({0, 0});

    int l; cin >> l;

    for(int i = 0; i < l; i++) {
        int x; char c;
        cin >> x >> c;
        q.push({x, c});
    }

    bool isgameend = false;

    while(!q.empty()) {
        int x = q.front().first;
        char c = q.front().second;
        q.pop();

        isgameend = false;

        for(int i = 0; i < x - lasttime; i++) {
            answer++;
            nowx += dx[nowdir];
            nowy += dy[nowdir];
            
            if(nowx < 0 || nowx >= n || nowy < 0 || nowy >= n || board[nowx][nowy] == 2) {
                isgameend = true;
                break;
            }

            if(board[nowx][nowy] == 1) {
                board[nowx][nowy] = 2;
                dq.push_front({nowx, nowy});
            }
            else if(board[nowx][nowy] == 0) {
                board[nowx][nowy] = 2;
                dq.push_front({nowx, nowy});
                int lastx = dq.back().first; int lasty = dq.back().second;
                dq.pop_back();
                board[lastx][lasty] = 0;
            }

        }

        if(isgameend) {
            break;
        }

        nowdir = returndir(nowdir, c);
        lasttime = x;
    }

    while(!isgameend) {
        answer++;
        nowx += dx[nowdir];
        nowy += dy[nowdir];

        if(nowx < 0 || nowx >= n || nowy < 0 || nowy >= n || board[nowx][nowy] == 2) {
            break;
        }
        if(board[nowx][nowy] == 1) {
            board[nowx][nowy] = 2;
            dq.push_front({nowx, nowy});
        }
        else if(board[nowx][nowy] == 0) {
            board[nowx][nowy] = 2;
            dq.push_front({nowx, nowy});
            int lastx = dq.back().first; int lasty = dq.back().second;
            dq.pop_back();
            board[lastx][lasty] = 0;
        }

    }

    cout << answer;

    
    return 0;
}