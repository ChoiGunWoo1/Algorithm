#include <iostream>
#include <algorithm>
#include <set>
#include <string>


using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, k;
    char typed; // 삽입이냐 삭제냐
    int number; // 숫자
    cin >> t;
    while(t--) {
        multiset<int> mm;
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> typed;
            cin >> number;
            if(typed == 'D') {
                if(mm.empty()) {
                    continue;
                }
                if(number == 1) {
                    mm.erase(prev(mm.end()));
                }
                else {
                    mm.erase(mm.begin());
                }
            }
            else {
                mm.insert(number);
            }
        }
            
        if(mm.empty()) {
            cout << "EMPTY" << '\n';
            continue;
        }
        auto first = mm.begin();
        auto last = prev(mm.end());
        cout << *last << " " << *first << '\n';
    }
    
    

    return 0;

}
