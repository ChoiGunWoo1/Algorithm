#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

char s[25];
bool brute[25];

int answer = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i <25; i++) {
        cin >> s[i];
    }
    for(int i = 18; i < 25; i++) {
        brute[i] = true;
    }
    do {
        vector<bool> visited(25);
        fill(visited.begin(), visited.end(), false);
        int st = 0;
        while(!brute[st]) {st++;}
        queue<int> q;
        visited[st] = true;
        q.push(st);
        int snum = 0;
        int ynum = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            int curx = cur / 5;
            int cury = cur % 5;
            if(s[cur] == 'S') {
                snum++;
            }
            else {
                ynum++;
            }
            for(int i = 0; i < 4; i++) {
                int nxtx = curx + dx[i];
                int nxty = cury + dy[i];
                if(nxtx < 0 || nxty < 0 || nxtx >= 5 || nxty >= 5) {
                    continue;
                }
                int nowidx = (nxtx * 5) + nxty;
                if(visited[nowidx]) {
                    continue;
                }
                if(!brute[nowidx]) {
                    continue;
                }
                q.push(nowidx);
                visited[nowidx] = true;
            }
        }
        if(snum + ynum == 7 && snum >= 4) {answer++;}
    } while(next_permutation(brute, brute+25));

    cout << answer;
    return 0;
}
