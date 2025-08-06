#include <iostream>
#include <algorithm>
using namespace std;


int CountNum(int n, int k) {
    int count = 0;
    for(long long i = k; i <= n; i *= k) {
        count += n / i;
    }
    return count;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int fivenum = CountNum(n, 5) - (CountNum(n-m, 5) + CountNum(m, 5));
    int twonum = CountNum(n, 2) - (CountNum(n-m, 2) + CountNum(m, 2));

    int answer = min(fivenum, twonum);
    
    cout << answer;

    

    return 0;
}