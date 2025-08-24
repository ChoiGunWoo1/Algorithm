#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool used[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        v.push_back(input);
    }

    int en = 0; int st = 0;
    int odd = 0;
    int answer = 0;

    while(en < n) {
        if(v[en] % 2 == 1) {
            odd++;
        }

        while(odd > k) {
            if(v[st] % 2 == 1) {
                odd--;
            }
            st++;
        }

        answer = max(answer, en - st + 1 - odd);
        en++;
    }
    

    cout << answer;

    return 0;
}