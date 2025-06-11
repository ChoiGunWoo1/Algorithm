#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

char field[14][8];
bool visited[14][8];
queue<pair<int, int>> checkplace; //뿌요가 있는 위치 저장

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


bool BFS(int curx, int cury) { // 같은색깔 blood fill
    vector<pair<int, int>> same;
    queue<pair<int, int>> q;
    q.push({curx, cury});
    visited[curx][cury] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        same.push_back({x,y});
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if(field[nx][ny] != field[curx][cury]) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    if(same.size() >= 4) { // 색깔이 이어진 갯수가 4 이상이라면 전부 없애고 true반환
        for(auto loc : same) {
            field[loc.first][loc.second] = '.';
        }
        return true;
    }
    else { // 아니라면 false반환
        return false;
    }
}

void AfterCrash() {
    for(int j = 0; j < 6; j++) {
        queue<char> q;
        // 아래서부터 위로 돌면서 남아있는 뿌요들을 큐에 넣음
        for(int i = 11; i >= 0; i--) {
            if(field[i][j] != '.') {
                q.push(field[i][j]);
            }
        }
        // 다시 아래에서부터 채움
        for(int i = 11; i >= 0; i--) {
            if(!q.empty()) {
                field[i][j] = q.front();
                q.pop();
            }
            else {
                field[i][j] = '.';
            }
        }
    }
    for(int i = 0; i < 12; i++) { // 새로운 checkplace 갱신
        for(int j = 0; j < 6; j++) {
            if(field[i][j] != '.') {
                checkplace.push({i,j});
            }
        }
    }
    for(int i = 0; i < 12; i++) { // 방문 여부 갱신
        fill(visited[i], visited[i] + 8, false);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 6; j++) {
            field[i][j] = s[j];
            if(field[i][j] != '.') {
                checkplace.push({i, j});
            }
        }
    }

    bool iscomboed = true;
    int answer = 0;
    while(iscomboed) {
        AfterCrash();
        iscomboed = false;
        while(!checkplace.empty()) {
            int curx = checkplace.front().first;
            int cury = checkplace.front().second;
            checkplace.pop();
            if(visited[curx][cury]) {
                continue;
            }
            if(BFS(curx, cury)) {
                iscomboed = true;
            }
        }
        if(iscomboed) {
            answer++;
        }
    }
    cout << answer;
    

    return 0;
}
