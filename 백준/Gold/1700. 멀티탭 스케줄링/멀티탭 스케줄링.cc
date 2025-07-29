#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;


int n, k;
vector<int> v;
int elec[102];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> elec[i];
    }

    int answer = 0;

    for(int i = 0; i < k; i++) {
        if(find(v.begin(), v.end(), elec[i]) != v.end()) {
            continue;
        }

        if(v.size() < n) {
            v.push_back(elec[i]);
            continue;
        }
        int idx = -1; int len = -1;

        for(int j = 0; j < n; j++) {
            int firstidx = 0;
            for(int l = i+1; l < k; l++) {
                if(v[j] == elec[l]) {
                    firstidx = l;
                    break;
                }
            }

            if(firstidx == 0) {
                idx = j;
                break;
            }
            if(firstidx > len) {
                len = firstidx;
                idx = j;
            }
        }
        v[idx] = elec[i];
        answer++;
    }


    cout << answer;

    
    
    return 0;
}