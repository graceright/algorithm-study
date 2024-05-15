//https://www.acmicpc.net/problem/3111
using namespace std;

#include <iostream>
#include <stack>
#include <string>

#define     left    0
#define     right   1

int p[2];
int leftright_p[2];
int wsize, psize;
string word[2];
string paper[2];
string leftright[2];

// 현재 stack 상단에 검열 문자열이 있는지 확인
bool isCensored(string &s, string &word)
{
    int ssize = s.size();
    //검열 문자열보다 크기가 작음 - false
    if(ssize < wsize) return false;
    for(int i = 0; i < wsize; i++)
    {
        if(s[ssize - wsize + i] != word[i]) return false;
    }
    
    return true;
}

// 문자열에서 검열 문자열의 크기만큼 제거
void popWord(string &s)
{
    s = s.substr(0,s.size()-wsize);
}

// stack의 값을 뒤집어서 string으로 반환
string stackReverse(stack<char> &s)
{
    string result;
    while(!s.empty())
    {
        result = s.top() + result;
        s.pop();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> word[left] >> paper[left];
    wsize = word[left].size();
    psize = paper[left].size();

    for(int i = wsize-1; i >= 0; i--)
    {
        word[right] += word[left][i];
    }
    for(int i = psize-1; i >= 0; i--)
    {
        paper[right] += paper[left][i];
    }
    while(p[left] + p[right] < psize)
    {
        for(int i = 0; i < 2; i++)  // i(0) : left, i(1) : right
        {
            while(p[left]+p[right] < psize)    
            {
                // if(i == 0) cout << "left " << p[i] << endl; else cout << "right "<< p[i] << endl;
                leftright[i][leftright_p[i]++] += paper[i][p[i]++];
                // cout << s[i].top() << " ";
                if(isCensored(leftright[i], word[i]))
                {//검열 문자열 상단에서 발견
                    // cout << word[i] << " detected" << endl;
                    popWord(leftright[i]);
                    break;
                }
            }
        }
    }

    // cout << leftright[left] << endl << leftright[right] << endl;
    // right stack 을 left stack으로 몰아넣고 검열 단어가 나오는지 마지막으로 확인
    for(int i = leftright[right].size()-1; i >= 0; i--)
    {
        leftright[left] += leftright[right][i];
        if(isCensored(leftright[left], word[left]))
        {
            popWord(leftright[left]);
        }
    }
    cout << leftright[left] << endl;
}