//https://www.acmicpc.net/problem/11066
using namespace std;
#include <stdio.h>
#include <vector>
//구간 [a,b]의 element의 합 반환
int sumOfvec(vector<int> &v, int a, int b)
{
    int ans(0);
    for(int i = a; i <= b; i++)
    {
        ans += v[i];
    }
    return ans;
}

int findMin(vector<int> &v, vector<vector<int>> &dp, int a, int b)
{
    if(dp[a][b] != 0 || b == a) //b==a는 0을 반환 자기자신은 합치는 비용이 들지 않음 
        return dp[a][b];
    if(b-a == 1)
        return dp[a][b] = v[a]+v[b];

    int answer = 9e8;
    int sumab = sumOfvec(v,a,b);
    for(int k = a; k < b; k++)
    {
        answer = min(answer, findMin(v,dp,a,k) + findMin(v,dp,k+1,b) + sumab);
    }
    return dp[a][b] = answer;
}

int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }
        vector<vector<int>> dp(n,vector<int>(n));
        printf("%d\n",findMin(v,dp,0,n-1));
    }
}