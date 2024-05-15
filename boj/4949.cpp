#define LOCAL




#include <bits/stdc++.h>
using namespace std;

const string Y = "yes";
const string N = "no";

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);

    while (true)
    {
        string str, answer(Y);
        getline(cin, str);
        if(str == ".")  //마지막 온점 하나 입력일 경우 종료 처리
            break;
        
        stack<char> s;
        for(char c : str) { //문자열의 모든 char에 대해 검사
            if(c == '(' || c == '[') {
                s.push(c);
            }
            else if(c == ')') {
                //check last pushed value is '('
                if(!s.empty() && s.top() == '(') {    //정상, pop
                    s.pop();
                }
                else {    //비정상, break하고 no 저장
                    answer = N;
                    break;
                }
            }
            else if(c == ']') {
                //check last pushed value is '['
                if(!s.empty()&& s.top() == '[') {    //정상, pop
                    s.pop();
                } else {    //비정상, break하고 no 저장
                    answer = N;
                    break;
                }
            }
        }
        //stack이 비어있는지 검사
        if(!s.empty())
            answer = N;

        cout << answer << endl;
    }
    

}