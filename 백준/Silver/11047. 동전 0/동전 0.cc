#include <iostream>
#include <algorithm>


using namespace std;


int coin[12];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int input;
    int answer = 0;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for(int i = n-1; i >= 0; i--) {
        int c = coin[i];
        answer += k / c;
        k = k % c;
    }
    cout << answer;

    
    return 0;
}