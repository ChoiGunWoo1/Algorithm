#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int n, m;

int ice[302][302];
bool visited[302][302];

int iceplace = 0;

vector<pair<int, int>> notmelted;
queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void melt() {
    vector<pair<int, int>> v;
    vector<tuple<int,int, int>> nv;
    for(auto point : notmelted) {
        int x = point.first;
        int y = point.second;
        int ic = ice[x][y];
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(ice[nx][ny] == 0) {
                if(ic > 0) {
                    ic -= 1;
                }
            }
        }
        if(ic != 0) {
            v.push_back({x,y});
        }
        nv.push_back({x, y, ic});
    }
    notmelted.swap(v);
    for(auto cur : nv) {
        int f, s, ic;
        tie(f, s, ic) = cur;
        ice[f][s] = ic;
    }
}

bool bfs() {
    if(notmelted.empty()) {
        return false;
    }
    for(int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + m, false);
    }
    pair<int, int> point = *notmelted.begin();
    q.push(point);
    int leftice = 0;
    visited[point.first][point.second] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        leftice++;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(ice[nx][ny] == 0) {
                continue;
            }
            if(visited[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});

        }
    }
    if(leftice == notmelted.size()) {
        return false;
    }
    return true;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ice[i][j];
            if(ice[i][j] != 0) {
                notmelted.push_back({i, j});
            }
        }
    }
    int year = 0;
    while(notmelted.size()) {
        melt();
        year++;
        if(bfs()) {
            cout << year;
            break;
        }
    }
    if(notmelted.empty()) {
        cout << 0;
    }
    
    


    return 0;
}
