#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, I;
    cin >> N >> K >> I;


    int answer = 0;
    while(K != I) {
        K = (K+1) / 2;
        I = (I+1) / 2;
        answer++;
    }
    cout << answer;

    return 0;
}