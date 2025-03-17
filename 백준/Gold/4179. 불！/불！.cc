#include <iostream>
#include <string>
#include <queue>


using namespace std;

int R, C;
char maze[1002][1002]; // 미로모양
int fire[1002][1002]; // 불의 경로
int Jihoon[1002][1002]; // 지훈의 경로
queue<pair<int, int>> fq; // 불의 루트를 저장할 queue
queue<pair<int, int>> jq; // 지훈의 루트를 저장할 queue
int etime = -1; // 탈출시간


void solution() // BFS 활용
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    // 1. 불이 옮겨붙는 루트 계산
    while(!fq.empty()) {
        int nowfx = fq.front().first;
        int nowfy = fq.front().second;
        fq.pop();
        for(int i = 0; i < 4; i++) {
            int newfx = nowfx + dx[i];
            int newfy = nowfy + dy[i];
            if(newfx < 0 || newfx >= R || newfy < 0 || newfy >= C) { // 미로 범위를 벗어나거나
                continue;
            }
            if(maze[newfx][newfy] == '#' || fire[newfx][newfy] >= 0) { // 벽이거나, 이미 불이 붙은 곳이거나
                continue;
            }
            fire[newfx][newfy] = fire[nowfx][nowfy] + 1; // 불의 경로 갱신후 큐에 넣음
            fq.push(make_pair(newfx, newfy));
        }
    }
    //2. 지훈이 갈수 있는 루트 계산
    while(!jq.empty()) {
        int nowjx = jq.front().first;
        int nowjy = jq.front().second;
        jq.pop();
        for(int i = 0; i < 4; i++) {
            int newjx = nowjx + dx[i];
            int newjy = nowjy + dy[i];
            if(newjx < 0 || newjx >= R || newjy < 0 || newjy >= C) { // 미로 범위를 벗어난다면
                etime = Jihoon[nowjx][nowjy] + 1; //탈출한것이므로, 현재 미로의 경로를 탈출 시간에 갱신후 함수종료
                cout << etime;
                return; 
            }
            if(maze[newjx][newjy] == '#' || Jihoon[newjx][newjy] >= 0) {
                continue; // 벽에 막히거나, 지훈이 이미 방문했거나
            }
            if(fire[newjx][newjy] != -1 && fire[newjx][newjy] <= Jihoon[nowjx][nowjy] + 1) {
                continue; // 이미 불이 붙은 곳이라면 갈수 없음
            }
            Jihoon[newjx][newjy] = Jihoon[nowjx][nowjy] + 1; // 그 외의 경우라면 지훈의 경로를 갱신후 탐색을 위해 queue에 삽입
            jq.push(make_pair(newjx, newjy));
        }
    }
    cout << "IMPOSSIBLE";
    return;


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> R >> C;
    for(int u = 0; u < 1002; u++) { // 각 경로 초기화
        for(int v = 0; v < 1002; v++) {
            fire[u][v] = -1;
            Jihoon[u][v] = -1;
        }
    }
    for(int i = 0; i < R; i++) { // 미로 입력받기
        cin >> s;
        for(int j = 0; j < C; j++) {
            maze[i][j] = s[j];
            if(maze[i][j] == 'J') {
                jq.push(make_pair(i, j));
                Jihoon[i][j] = 0;
            }
            else if(maze[i][j] == 'F') {
                fq.push(make_pair(i, j));
                fire[i][j] = 0;
            }
        }
    }
 
    solution();

    return 0;
}