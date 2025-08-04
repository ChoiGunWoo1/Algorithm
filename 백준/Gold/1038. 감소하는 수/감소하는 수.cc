#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<long long> v;

void Checknums(long long num, int last_num) {
    v.push_back(num);
    for(int i = 0; i < last_num; i++) {
        Checknums(num * 10 + i, i);
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++) {
        Checknums(i, i);
    }
    
    sort(v.begin(), v.end());

    int n; cin >> n;

    if(n >= v.size()) {
        cout << -1;
    }
    else {
        cout << v[n];
    }

    return 0;
}