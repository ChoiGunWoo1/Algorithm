#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

vector<bool> v;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int k;
    
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
        v.push_back(false);
    }
    v[1] = true;

    int check = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i]) {
            continue;
        }
        v[i] = true;
        check++;
        if(check == k) {
            cout << i;
            return 0;
        }
        for(int j = i; j <= n; j += i) {
            if(v[j] == true) {
                continue;
            }
            v[j] = true;
            check++;
            if(check == k) {
                cout << j;
                return 0;
            }
        }
    }

    
    
    return 0;
}