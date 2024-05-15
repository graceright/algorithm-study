#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct element
{
    int weight, value;
    bool isJewel;
    element(bool j, int w, int v=0) //가방은 value가 필요없으므로 뒤로 빼서 선택적 요소로 만든다.
    {
        weight = w;
        value = v;
        isJewel = j;
    }
};

bool cmpBagJewel(const element &a, const element &b)
{
    //기본 세팅은 weight 오름차순이지만, weight가 같은데 둘 중 하나가 가방이라면, 가방이 무조건 뒤에 와야 함
    if(a.weight == b.weight)
    {
        if(a.isJewel == false && b.isJewel == true)
        {   //a가 가방 : a b 순이 뒤바뀌어야 하므로 false
            return false;
        }
        else if(a.isJewel == true && b.isJewel == false)
        {   //b가 가방 : a b순이 유지되어야 하므로 true
            return true;
        }
    }
    return a.weight < b.weight;
}

struct pqvalueMax
{
    bool operator()(const element& a, const element& b)
    {   //보석 value 내림차순(max heap)이어야 함
        return a.value < b.value;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N,K;
    long long ans(0);
    cin >> N >> K;
    vector<element> v;
    priority_queue<element,vector<element>,pqvalueMax> pq;
    for(int i = 0; i < N; i++)
    {
        int M,V;
        cin >> M >> V;
        v.push_back(element(true,M,V));
    }
    for(int i = 0; i < K; i++)
    {
        int C;
        cin >> C;
        v.push_back(element(false,C));
    }
    sort(v.begin(), v.end(), cmpBagJewel);
    // for(auto ele : v)
    // {
    //     if(ele.isJewel)
    //         printf("J(%d,%d)",ele.weight,ele.value);
    //     else
    //         printf("B(%d)",ele.weight);
    // }
    for(auto ele : v)
    {
        if(ele.isJewel) pq.push(ele);
        else    //가방출현
        {
            if(pq.empty())  //넣을 보석이 없음
            {
                K--; continue;  //가방개수 감소시키고, 다음으로 넘어감
            }
            ans += pq.top().value;
            pq.pop();

            if(--K == 0)  //가방이 다떨어졌다면 미리 종료
                break;
        }
    }
    cout << ans << "\n";

}