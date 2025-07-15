#include <iostream>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    multiset<ll> s;

    for(int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        ll num[12];
        int pow = 0;
        ll answer = 0;
        while(input > 0) {
            ll n = input % 10;
            input = input / 10;
            num[pow] = n;
            pow++;
        }
        for(int k = 0; k < pow; k++) {
            ll x = num[k];
            for(int m = 0; m < pow-k-1; m++) {
                x *= 10;
            }
            answer += x;
        }
        s.insert(answer);
    }

    for(auto a : s) {
        cout << a << '\n';
    }
    
    return 0;
}