#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int x = 0;
    int num = 1;
    while(x < 1000) {
        for(int i = 0; i < num; i++) {
            v.push_back(num);
            x++;
        }
        num++;
    }

    int a, b;
    cin >> a >> b;
    int answer = 0;
    for(int i = a-1; i < b; i++) {
        answer += v[i];
    }
    
    cout << answer;

    return 0;
}