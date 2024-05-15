//https://www.acmicpc.net/problem/6549
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int cnt{};
    long long result{-1};
    scanf("%d", &cnt);
    vector<long long> rect(cnt);
    for(int i = 0; i < cnt; i++)
    {
        scanf("%lld", &rect[i]);
    }
    //===================================
    stack<long long> s;
    for(int i = 0; i < cnt; i++)
    {
        while(!s.empty() && rect[s.top()] > rect[i])    //넣으려는 사각형의 높이가 감소하면 현재 스택에 있는 사각형에 대한 검사가 필요함
        {
            long long height {rect[s.top()]}; s.pop();
            long long left = s.empty() ? 0 : s.top()+1;
            long long right = i-1;
            result = max(result, (right-left+1)*height);
            // printf("%d rect max size : %d X (%d - %d +1 )\n",height,height,right,left);
        }
        s.push(i);
    }
    //스택에 남아있는 사각형들에 대해 최대 높이 처리하기
    while(!s.empty())
    {
        long long height {rect[s.top()]}; s.pop();
        long long left = s.empty() ? 0 : s.top()+1;
        long long right = cnt-1;    //무조건 끝이 오른쪽이므로 
        result = max(result, (right-left+1)*height);
        // printf("%d rect max size : %d X (%d - %d +1 )\n",height,height,right,left);
    }
    printf("%lld\n",result);
}