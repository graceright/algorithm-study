#define LOCAL
#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);

    string str = "";
    int answer = 0;
    vector<int> numvec;
    getline(cin,str);

    regex re("[-]?\\d{1,5}");   //regex 정의 : 앞에 -가 붙을수도 있으며 digit이 1~5자리인 패턴의 값

    auto start = sregex_iterator(str.begin(), str.end(), re);
    auto end = sregex_iterator();

    while(start != end) {
        numvec.push_back(stoi(start->str()));
        ++start;
    }


    bool minusExist = false;
    int acc = 0;
    for(int item : numvec) {
        if(minusExist) {    //이전에 음수가 나왔음
            if(item >= 0) {
                acc += item;
            } else {    //음수가 또 나옴 : 축적된 acc값을 answer에 반영하고 acc 초기화
                answer -= acc;
                acc = abs(item);
            }
        } else {
            if(item >= 0) {
                answer += item;
            } else {
                minusExist = true;
                acc = abs(item);
            }

        }
    }
    answer -= acc;

    cout << answer << endl;  

    
}