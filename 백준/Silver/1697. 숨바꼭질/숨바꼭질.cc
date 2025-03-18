#include <iostream>
#include <string>
#include <queue>
#define maxnum 100002


using namespace std;

int N, K;

int route[maxnum];
queue<int> q;


void solution() // BFS 활용
{
    for(int i = 0; i < maxnum; i++) {
        route[i] = -1;
    }

    q.push(N);
    route[N] = 0;
    while(!q.empty()) { 
        int now = q.front();
        q.pop();
        int c1 = now + 1; // 각 케이스 정리(+1, -1, *2)
        int c2 = now - 1;
        int c3 = now * 2;
        int newc[3] = {c1, c2, c3};
        for(int j = 0; j < 3; j++) {
            if(newc[j] < 0 || newc[j] > 100000) { // 범위에서 벗어나면 x
                continue;
            }
            if(route[newc[j]] >= 0) { // 이미 방문한 곳이라면 x
                continue;
            }
            if(newc[j] == K) {
                route[K] = route[now] + 1; // 동생을 찾았다면면
                return;
            }
            route[newc[j]] = route[now] + 1;
            q.push(newc[j]);
        }

    }
    return;


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    solution();
    cout << route[K];
    

    

    return 0;
}