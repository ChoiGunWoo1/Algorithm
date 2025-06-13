#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int mp[22][22];

int dice[2][4] = {{0,0,0,0}, {0,0,0,0}};

void move_dice(int dir) {
    int newdice[4];
    if(dir == 1) {
        for(int i = 0; i < 4; i++) {
            if(i == 0) {
                newdice[i] = dice[0][3];
                continue;
            }
            newdice[i] = dice[0][i-1];
        }
        for(int i = 0; i < 4; i++) {
            dice[0][i] = newdice[i];
        }
    }
    else if(dir == 2) {
        for(int i = 0; i < 4; i++) {
            if(i == 3) {
                newdice[i] = dice[0][0];
                continue;
            }
            newdice[i] = dice[0][i+1];
        }
        for(int i = 0; i < 4; i++) {
            dice[0][i] = newdice[i];
        }
    }
    if(dir == 1 || dir == 2) {
        dice[1][1] = dice[0][1];
        dice[1][3] = dice[0][3];
        return;
    }
    if(dir == 3) {
        for(int i = 0; i < 4; i++) {
            if(i == 3) {
                newdice[i] = dice[1][0];
                continue;
            }
            newdice[i] = dice[1][i+1];
        }
        for(int i = 0; i < 4; i++) {
            dice[1][i] = newdice[i];
        }
    }
    else if(dir == 4) {
        for(int i = 0; i < 4; i++) {
            if(i == 0) {
                newdice[i] = dice[1][3];
                continue;
            }
            newdice[i] = dice[1][i-1];
        }
        for(int i = 0; i < 4; i++) {
            dice[1][i] = newdice[i];
        }
    }
    dice[0][1] = dice[1][1];
    dice[0][3] = dice[1][3];
    return;
} 



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int curx, cury; cin >> curx >> cury;
    int k; cin >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    while(k--) {
        int order;
        cin >> order;
        if(order == 1) {if(cury + 1 >= m) {continue;} cury += 1; }
        else if(order == 2) { if(cury - 1 < 0) {continue;} cury -= 1;}
        else if(order == 3) { if(curx - 1 < 0) {continue;} curx -= 1; }
        else if(order == 4) { if(curx + 1 >= n) {continue;} curx += 1; }

        move_dice(order);
        if(mp[curx][cury] == 0) {
            mp[curx][cury] = dice[0][3];
            cout << dice[0][1] << '\n';
            continue;
        }
        else {
            dice[0][3] = mp[curx][cury];
            dice[1][3] = mp[curx][cury];
            mp[curx][cury] = 0;
            cout << dice[0][1] << '\n';
            continue;
        }
    }
    
    
    return 0;
}