#include <iostream>


using namespace std;

int N;
int answer = -1;
int board1[22][22];
int board2[22][22];

void tilt(int i) { // 일단 왼쪽으로 옮기는걸 구현
    int j[N];
    for(int n = 0; n < N; n++) {
        j[n] = board2[i][n];
    }
    int idx = 0;
    int nj[N] = {0, };
    for(int k = 0; k < N; k++) {
        if(j[k] == 0) {
            continue;
        }
        if(nj[idx] == 0) {
            nj[idx] = j[k];
        }
        else if(nj[idx] == j[k]) {
            nj[idx] *= 2;
            idx++;
        }
        else {
            idx++;
            nj[idx] = j[k];
        }
    }

    for(int y = 0; y < N; y++) {
        board2[i][y] = nj[y];
    }
}

void Rotate() { //0이면 왼쪽, 1이면 90도로 한번 돌려서 위쪽, 2면 180도로 돌려서 오른쪽, 3이면 270도로 돌려서 아래쪽이 나온다.
    int temp[22][22];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            temp[i][j] = board2[N-j-1][i];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board2[i][j] = temp[i][j];
        }
    }
}

void Moving(int dir) {
    while(dir--) {
        Rotate();
    }
    for(int i = 0; i < N; i++) {
        tilt(i);
    }
}




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board1[i][j];
        }
    }
    int way = 1;
    for(int i = 0; i < 5; i++) {
        way *= 4;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board2[i][j] = board1[i][j];
        }
    }
    for(int turn = 0; turn < way; turn++) {
        int tmp = turn;
        for(int i = 0; i < 5; i++) {
            int dir = tmp % 4;
            tmp /= 4;
            Moving(dir);
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(answer < board2[i][j]) {
                    answer = board2[i][j];
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        
    }

    cout << answer;
    
    
    return 0;
}