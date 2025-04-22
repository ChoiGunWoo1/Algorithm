#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if(abs(a) > abs(b)) {
            return true;
        }
        else if(abs(a) == abs(b)) {
            if(a > b) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};

priority_queue<int, vector<int>, cmp> pq;



int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    int N, input;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input;
        if(input == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(input);
        }
    }
    

    return 0;
}
