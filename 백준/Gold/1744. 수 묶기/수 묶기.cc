#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;





int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int answer = 0;
    vector<int> plus;
    vector<int> minus;
    int zero = 0;
    int one = 0;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if(input == 1) {
            one += 1;
        }
        else if(input == 0) {
            zero += 1;
        }
        else if(input > 0) {
            plus.push_back(input);
        }
        else if(input < 0) {
            minus.push_back(input);
        }
    }
    // 아이디어1 : 양수는 큰 순서대로 묶어서 곱하고, 음수는 작은 순서대로 묶어서 곱하는게 이득
    sort(plus.begin(), plus.end(), greater<>());
    sort(minus.begin(), minus.end());

    for(int i = 0; i + 1 < plus.size(); i += 2) {
        int lash = plus[i] * plus[i+1];
        answer += lash;
    }
    if(plus.size() % 2 == 1) {
        answer += plus.back();
    }
    for(int i = 0; i + 1 < minus.size(); i += 2) {
        int lash = minus[i] * minus[i+1];
        answer += lash;
    }
    // 아이디어2 : 음수가 남고, 0이 순열에 있다면 0과 곱해서 음수를 없애는것이 이득
    if(minus.size() % 2 == 1) {
        if(zero == 0) {
            answer += minus.back();
        }
    }
    // 아이디어3 : 1은 곱해도 의미 없으니 묶지 않고 따로 더하는게 이득
    while(one--) {
        answer += 1;
    }
    
    
    cout << answer;
    
    return 0;
}