#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

stack<int> st1; // 처음 수열을 담아놓을 스택
stack<int> st2; // 현재 확인할 NGE(i) 보다 오른쪽에 있는 숫자들을 담아놓은 스택
int answer[1000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) { // 수열을 입력받아 st1 스택에 저장
        int input;
        cin >> input;
        st1.push(input);
    }
    int cnt = n;
    while(!st1.empty()) { // 모든 NGE확인할때까지 반복
        int cur = st1.top(); // 현재 확인할 NGE 숫자
        int rbn = -1; // 기본값은 nge = -1(없다는 가정하에)
        while(!st2.empty()) {
            int right = st2.top(); // 만약 왼쪽부터 차례로 봤는데
            if(right > cur) { // 현재보다 크다면
                rbn = right; // 반복을 중지하고 오큰수는 right가 됨
                break;       // -> 왜? nge확인할 숫자의 오른쪽에 있는 숫자중 크면서가장 왼쪽에 있는 숫자이므로
            }
            st2.pop(); // 작다면 pop하고 그다음 오른쪽수를 확인
        }              // pop해도 됨-> pop당한 숫자가 오큰수가 될수가 없음-> 이제 st2에 집어넣을 숫자가 더 크기 때문
        answer[cnt] = rbn; // 오큰수를 저장하고
        st1.pop(); // st1에서 pop
        st2.push(cur); // 더 오른쪽에 있는 숫자로 st2에 넣음
        cnt--; // 현재 인덱스 확인
    }
    for(int i = 1; i <= n; i++) {
        cout << answer[i] << " "; // 정답출력
    }
    
    return 0;

}
