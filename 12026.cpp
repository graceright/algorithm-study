//https://www.acmicpc.net/problem/12026
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string block;
int dp[1000];

//시작부터 idx자리까지 오는데 드는 최소 에너지
int go(int idx)
{
    if(idx == 0)
        return 0;
    if(dp[idx] != 0)
        return dp[idx];

    //dp[n] = min(dp[i] + (n-i)^2) 단, i번째는 n번째와 boj 순서가 맞아야 함
    for(int i = 0; i < idx; i++)
    {
        if(block[idx] == 'B' && block[i] != 'J')
            continue;
        if(block[idx] == 'O' && block[i] != 'B')
            continue;
        if(block[idx] == 'J' && block[i] != 'O')
            continue;
        
        int next = go(i);
        if(next != -1)
        {
            next += (idx-i)*(idx-i);
            if(dp[idx] == 0)
                dp[idx] = next;
            else
                dp[idx] = min(dp[idx], next);
        }
    }
    if(dp[idx] == 0)
        return dp[idx] = -1;    //방문 불가 지점
    else
        return dp[idx];
}

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> block;
    go(n-1);
    // for(int i = 0; i < n; i++)  cout << "dp" << dp[i] << endl;
    cout << go(n-1);
}