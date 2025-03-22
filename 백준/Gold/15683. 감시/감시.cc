#include <iostream>
#include <vector>

using namespace std;

int board1[8][8]; // 입력받은 사무실 배열 저장
int board2[8][8]; // 여러 경우의 사무실 상태를 저장할 공간
int N;
int M;
int cnum; // 카메라 개수
int answer; // 출력할 정답
int dx[4] = {1, 0, -1, 0}; // x방향
int dy[4] = {0, 1, 0, -1}; // y방향

vector<pair<int, int>> camera; // 카메라 위치 저장 배열

bool BoundC(int x, int y) { // 경계에 벗어났는지 검사
    if(x < 0 || x >= N || y < 0 || y >= M) {
        return true;
    }
    return false;
}

void Check(int x, int y, int dir) { //카메라라 방향에 따른 사무실 상태 변화
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(BoundC(x, y) || board2[x][y] == 6) { 
            return; //카메라가 보는 곳이 경계에서 벗어났거나 벽에 막힌다면
        }
        if(board2[x][y] != 0) { // 카메라면 그 카메라를 뚫고 본다
            continue;
        }
        else {
            board2[x][y] = 7; // 나머지 경우에는 그 곳이 보인다
        }
    }
}

void solution() { // 기본적으로 백 트래킹 방법 사용
    int way = 1;
    for(int i = 0; i < cnum; i++) { 
        way *= 4; // 카메라 개수에 따른 총 카메라 보는 방향 가짓수
    }
    for(int turn = 0; turn < way; turn++) { // 그 수만큼 반복
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                board2[i][j] = board1[i][j]; // board2 초기화
            }
        }
        int tmp = turn;
        for(int k = 0; k < cnum; k++) {
            int dir = tmp % 4; // 각 카메라 경우를 구하고
            tmp /= 4; // 4의 제곱인 이유는 보는 방향이 총 4가지이기 때문
            int x = camera[k].first; // 첫번째 카메라를 그 경우에 맞춰 board2에 저장
            int y = camera[k].second;
            if(board1[x][y] == 1) { // 각 경우에 맞게 카메라를 틀고 board2를 갱신
                Check(x, y, dir); 
            }
            else if(board1[x][y] == 2) {
                Check(x, y, dir);
                Check(x, y, dir + 2); // 각 경우에 dx dy index를 2씩 더하면 반대방향을 보게됨
            }
            else if(board1[x][y] == 3) {
                Check(x, y, dir);
                Check(x, y, dir + 1); // 각 경우에 dx dy index를 1씩 더하면 직각 방향을 보게됨
            }
            else if(board1[x][y] == 4){
                Check(x, y, dir);
                Check(x, y, dir+1);
                Check(x, y, dir+3);
            }
            else  {
                Check(x, y, dir);
                Check(x, y, dir+1);
                Check(x, y, dir+2);
                Check(x, y, dir+3);
            }
        }
        int cn = 0; // 볼수없는는 방의 개수 갱신
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board2[i][j] == 0) {
                    cn++; 
                }
            }
        }
        if(answer > cn) {
            answer = cn;// 만약 볼수 없는방이 더 작은 경우라면 갱신
        }
    }
}





int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) { // board1입력받기
            cin >> board1[i][j];
            if(board1[i][j] >=1 && board1[i][j] <= 5) {
                camera.push_back(make_pair(i, j)); // 카메라 위치 정보 저장
                cnum++;
            }
            else if(board1[i][j] == 0) { // 볼수없는 공간 처음에 갱신
                answer++;
            }
        }
    }
    solution();
    cout << answer;

    return 0;
}