#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int answer[500002];

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    stack<pair<int, int>> st1; //레이저 송신기 정보
    stack<pair<int, int>> st2; //오른쪽에서 내림차순이 유지되는동안의 레이저 송신기들을 저장
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        st1.push({i, input}); // 레이저 송신기 정보를 스택에 저장
    }
    while(!st1.empty()) {
        if(st2.empty()) { // st2가 비어있다는 것은 맨 처음 시작한다는 것
            auto cur = st1.top();
            st2.push(cur);
            st1.pop();
            continue;
        }

        if(st1.top().second < st2.top().second) { // st2에 내림차순으로 유지되는 가장 왼쪽 송신탑보다 st1의 맨오른쪽에 있는 송신탑이 낮으면 -> 전파를 수신하지 못함 + 내림차순이 유지
            auto nxt = st1.top(); 
            st2.push(nxt);
            st1.pop(); // st2에 정보를 넣고 st1에는 pop
            continue;
        }
        while(!st2.empty() && st2.top().second <= st1.top().second) { // st1의 맨 오른쪽 송신탑이 더 높다면 -> 전파를 수신하고 그 송신탑 정보를 answer 배열에 저장
            answer[st2.top().first] = st1.top().first; // st1의 송신탑 위치를 answer 배열에 저장
            st2.pop();
        }
        auto cur = st1.top();
        st2.push(cur);
        st1.pop();
    }
    while(!st2.empty()) { // st1이 비었는데도 st2에 남아있는 송신탑 -> 본인보다 왼쪽에 있는 송신탑은 모두 본인보다 높이가 낮다 -> 전파를 수신하지 못한다.
        answer[st2.top().first] = 0;
        st2.pop();
    }

    for(int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    
    return 0;

}
