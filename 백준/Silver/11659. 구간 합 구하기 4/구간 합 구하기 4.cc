#include <iostream>
#include <algorithm>


using namespace std;




int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int number[N+1];
    long long asum[N+1];
    number[0] = 0;
    asum[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> number[i];
    }
    for(int j = 1; j <= N; j++) {
        asum[j] = asum[j-1] + number[j];
    }
    int I, J;
    for(int k = 0; k < M; k++) {
        cin >> I >> J;
        cout << asum[J] - asum[I-1] << '\n';
    }



    return 0;
}