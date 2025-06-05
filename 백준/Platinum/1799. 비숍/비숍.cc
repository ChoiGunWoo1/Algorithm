#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int chess[12][12];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
int n;
vector<int> v1;
vector<int> v2;
int s1 = 0;
int s2 = 0;
int answer1 = 0;
int answer2 = 0;
bool ispos(int x, int y) {
    int curx = x; int cury = y;
    for(int i = 0; i < 4; i++) {
        curx = x; cury = y;
        while(true) {
            curx += dx[i];
            cury += dy[i];
            if(curx < 0 || cury < 0 || curx >= n || cury >= n) {
                break;
            }
            if(chess[curx][cury] == 2) { // 비숍이 있다면 대각선에
                return false;
            }
        }
    }
    return true;
}

void check1(int idx, int cnt) {
    for(int i = idx; i < s1; i++) {
        if(ispos(v1[i] / n, v1[i] % n)) {
            chess[v1[i] / n][v1[i] % n] = 2;
            check1(i+1, cnt+1);
            chess[v1[i] / n][v1[i] % n] = 1;
        }    
    }
    answer1 = max(answer1, cnt);
}

void check2(int idx, int cnt) {
    for(int i = idx; i < s2; i++) {
        if(ispos(v2[i] / n, v2[i] % n)) {
            chess[v2[i] / n][v2[i] % n] = 2;
            check2(i+1, cnt+1);
            chess[v2[i] / n][v2[i] % n] = 1;
        }    
    }
    answer2 = max(answer2, cnt);
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> chess[i][j];
            if(chess[i][j] == 1) {
                if((i+j) % 2 == 0) {
                    v1.push_back(i * n + j);
                    s1++;
                }
                else {
                    v2.push_back(i * n + j);
                    s2++;
                }
            }
        }
    }
    check1(0, 0);
    check2(0, 0);
    cout << answer1 + answer2;
    

    return 0;
}
