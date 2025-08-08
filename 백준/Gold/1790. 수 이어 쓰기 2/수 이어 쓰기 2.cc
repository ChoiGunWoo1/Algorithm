#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
using namespace std;

ll N, K;

ll Count(ll n) {
    ll a = n;
    ll i = 1;
    ll x = 9;
    ll num = 0;
    while(a > i * x) {
        a -= i * x;
        num += x;
        i++;
        x *= 10;
    }
    ll plus = a / i;
    ll check = a % i;
    ll targetnum = num + plus + (check == 0 ? 0 : 1);

    if(targetnum > N) {
        return -1;
    }

    string number = to_string(targetnum);
    if(check == 0) {
        return number.back() - '0';
    }
    else {
        return number[check-1] - '0';
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    cout << Count(K);

    return 0;
}