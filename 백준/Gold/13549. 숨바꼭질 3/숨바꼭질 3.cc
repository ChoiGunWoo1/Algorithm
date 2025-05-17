#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;


int cor[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    fill(cor, cor + 100002, -1);
    queue<int> q;
    q.push(n);
    cor[n] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int move[3] = {cur * 2, cur + 1, cur - 1};
        for(int i = 0; i < 3; i++) {
            int nxt = move[i];
            if(nxt < 0 || nxt >= 100001) {
                continue;
            }
            if(cor[nxt] >= 0) {
                    if(i == 0) {
                        if(cor[nxt] > cor[cur]) {
                            cor[nxt] = cor[cur];
                            continue;
                        }
                    }
                    else {
                        if(cor[nxt] > cor[cur] + 1) {
                            cor[nxt] = cor[cur] + 1;
                            continue;
                        }
                    }
                    continue;
            }
            if(i == 0) {
                cor[nxt] = cor[cur];
                if(nxt == k) {
                    continue;
                }
            }
            else {
                cor[nxt] = cor[cur] + 1;
                if(nxt == k) {
                    continue;
                }
            }
            q.push(nxt);
        }

    }
    cout << cor[k];

    return 0;
}
