#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin >> e >> s >> m;

    for(int i = e; i > 0; i += 15) {
        bool strue = false;
        if(s == 28) {
            if(i % 28 == 0) {
                strue = true;
            }
        }
        else {
            if(i % 28 == s) {
                strue = true;
            }
        }

        if(strue) {
            bool mtrue = false;
            if(m == 19) {
                if(i % 19 == 0) {
                    mtrue = true;
                }
            }
            else {
                if(i % 19 == m) {
                    mtrue = true;
                }
            }
            if(mtrue) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}