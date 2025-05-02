#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<int> v;
vector<char> answer;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input); // 얻어야할 배열 정보 저장
    }
    int cur = 0; // 현재 pop해서 얻어야할 v배열 인덱스
    for(int i = 1; i <= n; i++) { // 무조건 오름차순으로 push함
        while(!st.empty() && st.top() == v[cur]) {
            st.pop();
            answer.push_back('-');
            cur++;
        } // 스택의 top이 현재 얻어야할 수와 같다면 pop을 하고 정보 저장
        st.push(i); // 스택의 top이 현재 얻어야할 수와 다르다면 push하고 오름차순으로 넘어감 
        answer.push_back('+'); // push 정보 저장
    }
    while(!st.empty() && st.top() == v[cur]) {
        st.pop();
        answer.push_back('-');
        cur++;
    } // n까지 전부 push가 되었다면 남은 스택에서 배열 순서에 맞는 모든 수를 pop함
    if(st.empty()) { // 스택이 모두 비었다면 -> 수열을 만들 수 있다는 것
        for(auto nxt : answer) {
            cout << nxt << '\n';
        }
    }
    else {
        cout << "NO";
    }
    
   
    
    
    return 0;

}
