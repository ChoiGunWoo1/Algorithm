#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int ladder[32][22];
int N, M, H;
int answer = 4;

bool Outcome() {
    for(int j = 1; j <= N; j++) {
        int now = j;
        for(int i = 1; i <= H; i++) {
            if(ladder[i][now] == 0) {
                continue;
            }
            now = ladder[i][now];
        }

        if(now != j) {
            return false;
        }
    }
    return true;
}

void BackTracking(int idx, int depth, vector<pair<int, int>>& v) {
    if(depth >= answer) {
        return;
    }

    if(depth > 3) {
        return;
    }

    if(Outcome()) {
        answer = depth;
        return;
    }

    for(int i = idx; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if(ladder[x][y] != 0 || ladder[x][y+1] != 0) continue;

        ladder[x][y] = y+1;
        ladder[x][y+1] = y;

        BackTracking(i+1, depth+1, v);

        ladder[x][y] = 0;
        ladder[x][y+1] = 0;
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> H;

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = b+1;
        ladder[a][b+1] = b;
    }
    vector<pair<int, int>> v;
 

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N-1; j++) {
            if(ladder[i][j] == 0 && ladder[i][j+1] == 0) {
                v.push_back({i, j});
            }
        }
    }

    BackTracking(0, 0, v);
    
    if(answer > 3) {
        answer = -1;
    }
    

    cout << answer;
    
    return 0;
}