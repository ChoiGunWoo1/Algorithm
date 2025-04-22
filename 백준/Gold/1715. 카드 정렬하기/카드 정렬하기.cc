#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // pq는 기본적으로 내림차순이므로 오름차순으로 정렬

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int input;
    while(n--) { // 아이디어 : 제일 작은 값을 계속 더하가면 된다.
        cin >> input;
        pq.push(input);
    }
    int answer = 0;
    while(pq.size() > 1) {
        int min1 = pq.top();// 제일 작은 값을 더하고, 그 값을 pq에 추가하는 과정 반복
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1 + min2);
        answer += (min1 + min2);
    }
    cout << answer;
    
    
    

    return 0;

}
