//https://www.acmicpc.net/problem/14238
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[51][51][51][3][3]; //[a개수][b개수][c개수][전전날일한사람][전날일한사람] 일 경우 차후 조합으로 가능한지 저장,  초기화 -1
string s;
string answer;
int maximum[3]; //abc 한도

bool go(int a, int b, int c, int before2day, int before1day)
{
    int &ans = dp[a][b][c][before2day][before1day];
    if(a+b+c == s.size())//탈출 조건
    {
        return ans = true;
    }
    if(ans != -1)
    {
        return ans;
    }

    //A - 유효성검사 필요 X
    if(a < maximum[0] && go(a+1,b,c,before1day,0))
    {
        answer = 'A' + answer;
        return ans = true;
    }
    //B
    if(b < maximum[1] && before1day != 1 && go(a,b+1,c,before1day,1))
    {
        answer = 'B' + answer;
        return ans = true;
    }
    //C
    if(c < maximum[2] && before1day != 2 && before2day != 2 && go(a,b,c+1,before1day,2))
    {
        answer = 'C' + answer;
        return ans = true;
    }

    return ans = false;
}

int main()
{
    cin >> s;
    for(auto a : s)
    {
        maximum[a-'A']++;
    }
    memset(dp, -1, sizeof(dp));


    if(go(0,0,0,0,0))//어차피 A는 조건에 안걸리므로 일한사람이 없어도 0으로 통일함
    {
        cout << answer;
    }
    else
    {
        cout << -1;
    }

}