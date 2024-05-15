//https://www.acmicpc.net/problem/11060
using namespace std;

#include <iostream>
#include <vector>
#include <queue>

vector<int> map;
vector<int> count;
int main()
{
    int n;  scanf("%d", &n);
    count.resize(n, -1);
    count[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;   scanf("%d", &temp);
        map.push_back(temp);
    }
    if(n == 1)
    {
        printf("0");
        return 0;
    }
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int curPos {q.front()}; q.pop();    //현재 위치
        int curCount {count[curPos]};       //현재 점프 횟수
        int jumpMax {map[curPos]};          //현재 위치에서 가장 멀리 뛸 수 있는 위치
        // printf("pos:%d count:%d jumpMax:%d\n",curPos, curCount, jumpMax);
        if(curPos + jumpMax >= map.size()-1)   //도착 - bfs기 때문에 무조건 최소
        {
            printf("%d", curCount+1);
            return 0;
        }
        for(int i = 1; i <= jumpMax; i++)
        {
            if(count[curPos+i] != -1)
                continue;
            count[curPos+i] = curCount+1;
            q.push(curPos+i);
        }
    }
    printf("-1");
}