//https://www.acmicpc.net/problem/2109
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;  cin >> n;
    vector<pair<int,int>> university;
    priority_queue<int> pq;
    int maxDay(-1);
    while(n--)
    {
        int d,p;    cin >> p >> d;
        university.push_back(make_pair(d,p));   //일,금액
        maxDay = max(maxDay, d);
    }
    //날짜 넣기
    for(int i = 1; i <= maxDay; i++)
    {
        university.push_back(make_pair(i,-1));
    }
    sort(university.begin(), university.end(), 
    [](const pair<int,int> &a, const pair<int,int> &b)
    {   //날짜 내림차순...
        if(a.first == b.first) return a.second > b.second;  //날짜는 second가 -1이므로 무조건 뒤에올수있게 비용오름차순
        return a.first > b.first;
    });
    int result(0);
    for(auto ele : university)
    {
        if(ele.second == -1 && !pq.empty())
        {   //날짜이고, 할수있는 강의가 있을 때
            result += pq.top();   pq.pop();
        }
        else if(ele.second != -1)
        {   //강의인 경우 pq에 삽입
            pq.push(ele.second);
        }
    }
    cout << result << "\n";
}