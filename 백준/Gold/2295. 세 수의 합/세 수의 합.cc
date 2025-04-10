#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int one[1002];
vector<int> two;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> one[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            two.push_back(one[i] + one[j]); // 먼저 두수부터 더하는 경우를 구함
        }
    }
    sort(one, one+n);
    sort(two.begin(), two.end());
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            int a = one[i] - one[j]; // 세번째 수를 더한 경우가 원래 배열안에 있는지 이분탐색으로 체크
            if(binary_search(two.begin(), two.end(), a)) {
                cout << one[i];
                return 0;
            }
        }
    }
    
    


}