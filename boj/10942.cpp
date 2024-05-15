//https://www.acmicpc.net/problem/10942
using namespace std;
#include <iostream>
#include <vector>

vector<vector<int>> map;    //1 : 펠린드롬, 0: 펠린드롬 아님, -1: 아직 기록되지 않음
vector<int> nums;

bool isF2(int a, int b)
{
    if(map[a][b] != -1)
        return map[a][b];
    if(a == b)
        return map[a][b] = true;
    if(a > b)
        return true;
    if(nums[a] != nums[b])
        return map[a][b] = false;
    
    return map[a][b] = isF2(a+1,b-1);
}

int main()
{
    int N; scanf("%d", &N);
    map.resize(N+1,vector<int>(N+1,-1)); 
    nums.resize(N+1);
    for(int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);
    int M;  scanf("%d", &M);
    while(M--)
    {
        int a, b;   scanf("%d %d",&a,&b);
        printf("%d\n",isF2(a,b));
    }
}