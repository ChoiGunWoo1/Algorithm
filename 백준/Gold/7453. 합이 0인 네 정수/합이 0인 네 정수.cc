#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

vector<ll> A;
vector<ll> B;
vector<ll> C;
vector<ll> D;

vector<ll> AB;
vector<ll> CD;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll input1, input2, input3, input4;
        cin>> input1 >> input2 >> input3 >> input4;
        A.push_back(input1);
        B.push_back(input2);
        C.push_back(input3);
        D.push_back(input4);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll ab = A[i] + B[j];
            ll cd = C[i] + D[j];

            AB.push_back(ab);
            CD.push_back(cd);
        }
    }
    sort(CD.begin(), CD.end());

    ll answer = 0;

    for(auto sum : AB) {
        ll target = -sum;

        int st = 0;
        int en = n*n - 1;
        int lower = -1;
        while(st <= en) {
            int mid = (st + en) / 2;

            if(CD[mid] >= target) {
                if(CD[mid] == target) {
                    lower = mid;
                }
                en = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        if(lower == -1) {
            continue;
        }

        st = 0; en = n*n - 1;
        int upper = -1;

        while(st <= en) {
            int mid = (st + en) / 2;

            if(CD[mid] <= target) {
                if(CD[mid] == target) {
                    upper = mid;
                }
                st = mid + 1;
            }
            else {
                en = mid - 1;
            }
        }

        answer += (upper - lower) + 1;
    }

    cout << answer;
    

    return 0;
}