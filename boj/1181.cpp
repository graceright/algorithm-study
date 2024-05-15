#define LOCAL

#include <bits/stdc++.h>
using namespace std;

// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

// 길이가 짧은 것부터
// 길이가 같으면 사전 순으로
// 단, 중복된 단어는 하나만 남기고 제거해야 한다.

bool cmp(string a, string b) {
    
    if(a.length() != b.length()) {  //1. 길이
        return a.length() < b.length();
    } else {    //2. 길이가 같다면 사전순
        return a < b;
    }
}

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();   // getline을 위한 첫 \n 무시 
    vector<string> strvec; 

    for(int i = 0; i < n; i++) {
        string str = "";
        getline(cin,str);
        if(strvec.end() == find(strvec.begin(),strvec.end(),str)) { //중복 제거
            strvec.push_back(str);
        }
    }

    sort(strvec.begin(),strvec.end(),cmp);

    for(auto item : strvec) {
        cout << item << '\n';
    }

    return 0;

}