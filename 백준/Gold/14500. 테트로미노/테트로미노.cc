#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int paper[502][502];
bool visited[502][502];

int answer = 0;

void find_max(int x, int y, int cnt, int sv) {

    visited[x][y] = true;
    int nsv = sv + paper[x][y];

    if(cnt == 4) {
        visited[x][y] = false;
        answer = max(nsv, answer);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if(visited[nx][ny]) {
            continue;
        }
        find_max(nx, ny, cnt + 1, nsv);
    }

    visited[x][y] = false;

}

void Check_extra(int x, int y) {
    if(x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
        answer = max(answer, paper[x][y] + paper[x-1][y] + paper[x-1][y-1] + paper[x-1][y+1]);
    }
    if(x + 1 < n && y - 1 >= 0 && y + 1 < m) {
        answer = max(answer, paper[x][y] + paper[x+1][y] + paper[x+1][y-1] + paper[x+1][y+1]);
    }
    if(x - 1 >= 0 && x + 1 < n && y - 1 >= 0) {
        answer = max(answer, paper[x][y] + paper[x][y-1] + paper[x-1][y-1] + paper[x+1][y-1]);
    }
    if(x - 1 >= 0 && x + 1 < n && y + 1 < m) {
        answer = max(answer, paper[x][y] + paper[x][y+1] + paper[x-1][y+1] + paper[x+1][y+1]);   
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            find_max(i, j, 1, 0);
            Check_extra(i, j);
        }
    }

    cout << answer;

    
    return 0;
}