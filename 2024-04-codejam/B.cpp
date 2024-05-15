#include <bits/stdc++.h>

using namespace std;

vector<int> charge_v;
vector<int> fee_v;
vector<int> use_v;
int day,start,limit;
long long answer(-1);

void clearVariable()
{
    answer = -1;
    charge_v.clear();
    fee_v.clear();
    use_v.clear();
}

void dfs(int cur, int nowDay, long long usedFee, vector<vector<int>> &DP)
{
    if(nowDay > day)    //정산
    {
        if(cur >= start)
        {   //첫날보다 현재 잔여량이 많거나 같아야 함
            answer = (answer == -1) ? usedFee : min(answer,usedFee);
        }
        return;
    }

    //사용하지 않음
    int afterCharge = min(limit,cur+charge_v[nowDay-1]);
    int nextFee = usedFee+static_cast<long long>(fee_v[nowDay-1])*use_v[nowDay-1];
    if(DP[afterCharge][])
    dfs(afterCharge, nowDay+1, nextFee);  //vector index때문에 -1씩..
    //사용함 - 전기 확인
    if(cur >= use_v[nowDay-1])  //사용가능
    {
        dfs(cur-use_v[nowDay-1], nowDay+1, usedFee);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        if(i!=0)
            clearVariable();
        scanf("%d %d %d",&day,&start,&limit);
        int temp;
        for(int j = 0; j < day; j++)
        {
            scanf("%d", &temp);
            charge_v.push_back(temp);
        }
        for(int j = 0; j < day; j++)
        {
            scanf("%d", &temp);
            fee_v.push_back(temp);
        }
        for(int j = 0; j < day; j++)
        {
            scanf("%d", &temp);
            use_v.push_back(temp);
        }
        //행 : 날짜, 열 : 현재 해당하는 배터리, 값 : 최소 비용
        vector<vector<int>> DP(day,vector<int>(limit+1, -1));

    }
}