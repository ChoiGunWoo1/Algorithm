#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

vector<string> enter;
vector<string> leave;
vector<string> answer;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    string name;
    string inorout;
    for(int i = 0; i < n; i++) {
        cin >> name;
        cin >> inorout;
        if(inorout.compare("enter") == 0) {
            enter.push_back(name);
        }
        else {
            leave.push_back(name);
        }
    }
    sort(enter.begin(), enter.end());
    sort(leave.begin(), leave.end());
   
    auto it = enter.begin();
    auto seit = enter.begin();
    auto slit = leave.begin();
    string ns;
    
    while(it != enter.end()) {

        ns = *it;
        auto elit = upper_bound(leave.begin(), leave.end(), ns);
        auto next_it = upper_bound(enter.begin(), enter.end(), ns);
        if(next_it - seit > elit - slit) {
            answer.push_back(ns);
        }
        seit = next_it;
        slit = elit;
        it = next_it;
    }
    sort(answer.begin(), answer.end(), greater());
    for(auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << '\n';
    }
    

    return 0;

}