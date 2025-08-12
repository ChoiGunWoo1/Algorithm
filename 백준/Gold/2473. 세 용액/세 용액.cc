#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
vector<int> answer;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    long long best = LLONG_MAX;

    for(int i = 0; i < n-2; i++) {
        int st = i+1;
        int en = n-1;

        while(st < en) {
            long long sum = (long long)v[i] + v[st] + v[en];

            if(abs(sum) < best) {
                best = abs(sum);
                answer = {v[i], v[st], v[en]};
            }

            if(sum == 0) break;
            if(sum < 0) st++;
            if(sum > 0) en--;
        }
    }

    for (auto a : answer)
    {
        cout << a << " ";
    }

    return 0;
}