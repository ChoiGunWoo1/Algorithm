#include <iostream>
#include <algorithm>



using namespace std;




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int x, y;
        cin >> x >> y;

        int d = y - x;
        int n = 1;
        while((long long)n * n <= d) {
            n++;
        }
        n--;

        if(n * n >= d) {
            cout << 2 * n - 1;
        }
        else if(n * (n+1) >= d) {
            cout << 2 * n;
        }
        else {
            cout << 2 * n + 1;
        }
        cout << '\n';
    }

    return 0;
}