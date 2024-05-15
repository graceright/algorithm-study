//https://www.acmicpc.net/problem/3015
#include <cstdio>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    int n;    scanf("%d",&n);
    long long result {};
    stack<pair<int,int>> s;
    for(int i = 0; i < n; i++)
    {
        pair<int,int> temp;
        scanf("%d", &temp.first);
        temp.second = 1;
        while(!s.empty() && s.top().first < temp.first)
        {   //stack에 있는 모든 temp보다 키 작은 사람에 대해 볼 수 있는 사람 정산하기
            result++;   //temp와 pop할 사람쌍
            // printf("(%d,%d) : %d\n",s.top().first,temp.first,result);
            s.pop();
        }

        if(!s.empty())
        {
            if(s.top().first == temp.first)
            {
                temp.second = s.top().second+1;
                if(s.size() == s.top().second)
                {   //맨처음 오는 사람의 경우 맨앞사람이 없으므로
                    result+=temp.second-1;
                }
                else
                {
                    result+=temp.second; //같은 것이 누적된만큼 앞의 사람을 볼 수 있기 때문에
                }
            }
            else
            {
                result++;
            }
            // printf("(%d,%d) : %d\n",s.top().first, temp.first, result);
        }
        s.push(temp);
    }
    printf("%lld\n",result);
}