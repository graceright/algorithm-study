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
    cin >> str;
    str += '\n';

    string temp = "";
    bool minusExist = false;
    int acc = 0;

    for(char c : str) {
        if(minusExist) {    //모두 answer에서 뺌
            if(c == '+' || c == '-' || c == '\n') {
                answer -= stoi(temp);
                temp = "";
            } else {
                temp += c;
            }  
        } else {
            if(c == '+' || c == '-' || c == '\n') {
                answer += stoi(temp);
                temp = "";
                if(c == '-')
                    minusExist = true;
            } else {
                temp += c;
            } 

        }
    }

    




    cout << answer << endl;  

    
}