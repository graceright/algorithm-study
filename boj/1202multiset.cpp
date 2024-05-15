#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <limits.h>

using namespace std;

int N,K,LIMIT;
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second > b.second;
}

int main()
{
    cin >> N >> K;
    vector<pair<int,int>> jewelry(N);
    multiset<int> bags;
    for(int i = 0; i < N; i++)
    {
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for(int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;
        bags.insert(temp);
    }

    long long int answer(0);
    sort(jewelry.begin(), jewelry.end(), cmp);  //보석을 가치있는것 순으로 정렬
    for(auto j : jewelry)
    {
        auto it = bags.lower_bound(j.first);
        if(it != bags.end())    //추가 가능
        {
            answer += j.second;
            bags.erase(it);
            if(bags.empty()) break;
        }
    }

    cout << answer << "\n";



}