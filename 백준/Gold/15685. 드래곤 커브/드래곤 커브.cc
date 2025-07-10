#include <iostream>
#include <algorithm>
#include <queue>
#define Xplus 0
#define YMinus 1
#define XMinus 2
#define YPlus 3

using namespace std;

int board[102][102];


int CheckDragon() {
    int dragon = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1) {
                dragon++;
            }
        }
    }
    return dragon;
}

vector<int> DrawDragon(int d, int generation) {
    vector<int> dir;
    dir.push_back(d);
    for(int g = 0; g < generation; g++) {
        vector<int> tmp = dir;
        for(auto it = tmp.rbegin(); it != tmp.rend(); it++) {
            dir.push_back((*it + 1) % 4);
        }
    }
    return dir;
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> dir = DrawDragon(d, g);
        board[x][y] = 1;
        for(auto p : dir) {
            if(p == Xplus) {
                x += 1;
                board[x][y] = 1;
            }
            else if(p == YMinus) {
                y -= 1;
                board[x][y] = 1;
            }
            else if(p == XMinus) {
                x -= 1;
                board[x][y] = 1;
            }
            else {
                y += 1;
                board[x][y] = 1;
            }
        }
    }

    cout << CheckDragon();
    return 0;
}