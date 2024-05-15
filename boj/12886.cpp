//https://www.acmicpc.net/problem/12886
#include <iostream>
#include <vector>

using namespace std;
int sum;
vector<vector<bool>> isCalculated(1500,vector<bool>(1500,false));

void dfs(int a, int b)
{
    if(isCalculated[a][b]) return;  //이미 계산된 돌
    isCalculated[a][b] = true;
    vector<int> rock1{a,b,sum-a-b};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(rock1[i] < rock1[j])
            {   //대소관계 성립 : 새로운 돌 계산
                vector<int> rock2(rock1);
                rock2[i] += rock1[i];
                rock2[j] -= rock1[i];
                dfs(rock2[0], rock2[1]);
            }
        }
    }
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    sum = a+b+c;
    if(sum%3 != 0)
    {
        cout << "0\n";
        return 0;
    }
    dfs(a,b);
    if(isCalculated[sum/3][sum/3])  cout << "1\n";
    else cout << "0\n";
    return 0;
}