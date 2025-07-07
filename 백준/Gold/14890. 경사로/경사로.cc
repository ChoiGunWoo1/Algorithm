#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int board[102][102];

int n;
int answer = 0;

void Check(int L) {
    for(int i = 0; i < n; i++) {
        int seq = 0;
        int before = 0;
        bool canpass = true;
        for(int j = 0; j < n; j++ ){
            if(j == 0) {
                seq = 1;
                before = board[i][j];
                continue;
            }
            if(board[i][j] == before) {
                seq += 1;
                continue;
            }
            if(board[i][j] - before == 1) {
                if(seq >= L) {
                    seq = 1;
                    before = board[i][j];
                }
                else {
                    canpass = false;
                    break;
                }
            }
            if(before - board[i][j] == 1) {
                int tmpseq = 0;
                int nowbefore = board[i][j];
                int t = j;
                while(t < n && tmpseq < L) {
                    if(nowbefore != board[i][t]) {
                        break;
                    }
                    t++;
                    tmpseq++;
                }
                if(tmpseq < L) {
                    canpass = false;
                    break;
                }
                before = board[i][j];
                seq = 0;
                j = t-1;
                continue;
            }
            if(abs(board[i][j] - before) > 1) {
                canpass = false;
                break;
            }
        }
        if(canpass) {
            answer++;
        }
    }
    for(int j = 0; j < n; j++) {
        int seq = 0;
        int before = 0;
        bool canpass = true;
        for(int i = 0; i < n; i++ ){
            if(i == 0) {
                seq = 1;
                before = board[i][j];
                continue;
            }
            if(board[i][j] == before) {
                seq += 1;
                continue;
            }
            if(board[i][j] - before == 1) {
                if(seq >= L) {
                    seq = 1;
                    before = board[i][j];
                }
                else {
                    canpass = false;
                    break;
                }
            }
            if(before - board[i][j] == 1) {
                int tmpseq = 0;
                int nowbefore = board[i][j];
                int t = i;
                while(t < n && tmpseq < L) {
                    if(nowbefore != board[t][j]) {
                        break;
                    }
                    t++;
                    tmpseq++;
                }
                if(tmpseq < L) {
                    canpass = false;
                    break;
                }
                before = board[i][j];
                seq = 0;
                i = t-1;
                continue;
            }
            if(abs(board[i][j] - before) > 1) {
                canpass = false;
                break;
            }
        }
        if(canpass) {
            answer++;
        }
    }
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    Check(l);

    cout << answer;
    
    
    return 0;
}