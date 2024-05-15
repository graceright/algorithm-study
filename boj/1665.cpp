//https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    priority_queue<int> leftMax;    //최대 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> rightMin;    //최소 우선순위 큐
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int temp;
        scanf("%d", &temp);
        //1. 최대 우선순위 큐에 삽입
        leftMax.push(temp);
        if(i%2 == 0)    //짝수번째
        {
            temp = leftMax.top();   leftMax.pop();
            rightMin.push(temp);
        }
        else if(!rightMin.empty() && leftMax.top() > rightMin.top())
        {   // 교환
            int l{leftMax.top()}, r{rightMin.top()};
            leftMax.pop();  rightMin.pop();
            leftMax.push(r);    rightMin.push(l);
        }
        printf("%d\n", leftMax.top());
    }
}