#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> v;
int S[14];

int k;
void Answer(int idx) {

    if(v.size() == 6) {
        for(auto num : v) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i < k; i++) {
        v.push_back(S[i]);
        Answer(i+1);
        v.pop_back();
    }
}




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    while(true) {

        cin >> k;

        if(k == 0) {
            break;
        }
        for(int i = 0; i < k; i++) {
            cin >> S[i];
        }

        Answer(0);
        cout << '\n';
    }

    


    return 0;
}
