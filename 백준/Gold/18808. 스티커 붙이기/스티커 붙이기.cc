#include <iostream>


using namespace std;

int N, M, R, C, K;

int moniter[40][40]; // 모니터
int paper[10][10]; // 모눈종이

void Rotate() { // 모눈종이 스티커 회전하는 함수
    int temp[10][10];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            temp[i][j] = paper[i][j];
        }
    }
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < R; j++) {
            paper[i][j] = temp[R-j-1][i];
        }
    }
    swap(R, C);
}

bool Checkput(int x, int y) { // 스티커를 모니터에 붙일 수 있는지 여부 체크
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(paper[i][j] == 1 && moniter[i+x][j+y] == 1) {
                return false;
            }
        }
    }
    return true;
}

void Putsticker(int x, int y) { // 스티커를 모니터에 붙임
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(paper[i][j] == 1) {
                moniter[i+x][j+y] = 1;
            }
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    while(K--) { // K개의 스티커 개수만큼 반복
        cin >> R >> C;
        for(int i = 0; i < R; i++) { // 스티커 모눈종이에 입력
            for(int j = 0; j < C; j++) {
                cin >> paper[i][j];
            }
        }
        for(int r = 0; r < 4; r++){ // 총 4번 실행(0, 90, 180, 270)
            bool pasteable = false; // 스티커를 붙일 수 있는지 bool 변수
            for(int i = 0; i <= N-R; i++) {
                if(pasteable) {
                    break;
                }
                for(int j = 0; j <= M-C; j++) {
                    if(Checkput(i, j)) { // 스티커를 붙일 수 있다면 pastable 변수를 true로
                        Putsticker(i, j);
                        pasteable = true;
                        break;
                    }

                }
            }
            if(pasteable) { // 스티커를 붙일 수 있다면 다음 스티커를 붙임
                break;
            }
            Rotate(); // 스티커를 붙일 수 없다면 회전해서 다음 경우 생각
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++) { // 총 스티커가 붙여진 넓이 계산
        for(int j = 0; j < M; j++) {
            if(moniter[i][j] == 1) {answer++;}
        }
    }
    cout << answer;
    return 0;
}