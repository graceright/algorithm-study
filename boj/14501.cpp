//https://www.acmicpc.net/problem/14501
//dfs
#include <iostream>
#include <vector>
#include <utility>

#define MAX_DAY     15
using namespace std;
int DAY;
int max_profit;
vector<pair<int,int>> schedule(MAX_DAY+1);  //0 안씀

void dfs(int cur, int money)
{
    if(cur > DAY+1)   //초과한 경우
    {
        return;
    }
    if(cur == DAY+1)    //전날 일이 퇴사일과 딱 맞을 경우
    {
        max_profit = max(max_profit, money);
        return;
    }
    dfs(cur+schedule[cur].first, money+schedule[cur].second);
    dfs(cur+1, money);
}

int main()
{
    cin >> DAY;
    for(int i = 1; i <= DAY; i++)
    {
        int t, p;
        cin >> t >> p;
        schedule[i] = make_pair(t,p);
    }
    //================================================================
    dfs(1,0);
    cout << max_profit << "\n";
}