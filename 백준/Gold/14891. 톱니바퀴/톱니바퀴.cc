#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cog[4][8];

bool visited[4];

void rotating(int cognum, int dir) {
    int newcog[8];
    if(dir == 1) {
        for(int i = 0; i < 8; i++) {
            if(i == 0) {
                newcog[i] = cog[cognum][7];
                continue;
            }
            newcog[i] = cog[cognum][i-1];
        }
    }
    else {
        for(int i = 0; i < 8; i++) {
            if(i == 7) {
                newcog[i] = cog[cognum][0];
                continue;
            }
            newcog[i] = cog[cognum][i+1];
        }
    }
    for(int i = 0; i < 8; i++) {
        cog[cognum][i] = newcog[i];
    }
}

void rotate_and_check(int cognum, int dir) {
    if(visited[cognum]) {
        return;
    }
    visited[cognum] = true;
    if(cognum - 1 >= 0) {
        if(cog[cognum][6] != cog[cognum-1][2]) {
            if(dir == 1) {
                rotate_and_check(cognum - 1, -1);
            }
            else {
                rotate_and_check(cognum - 1, 1);
            }
        }
    }
    if(cognum + 1 < 4) {
        if(cog[cognum][2] != cog[cognum+1][6]) {
            if(dir == 1) {
                rotate_and_check(cognum+1, -1);
            }
            else {
                rotate_and_check(cognum+1, 1);
            }
        }
    }
    rotating(cognum, dir);
    
}




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++) {
            cog[i][j] = s[j] - '0';
        }
    }

    int n; cin >> n;
    while(n--) {
        fill(visited, visited + 4, false);
        int num, dir;
        cin >> num >> dir;
        rotate_and_check(num-1, dir);
    }

    int answer = 0;

    for(int i = 0; i < 4; i++) {
        int score = 1;
        for(int j = 0; j < i; j++) {
            score *= 2;
        }
        answer += cog[i][0] * score;
    }

    cout << answer;
    return 0;
}