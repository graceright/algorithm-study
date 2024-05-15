//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define WALL        3

int N,M,zero,answer(-1);
vector<vector<int>> labmap(10,vector<int>(10,1));
vector<pair<int,int>> virus;
int dy[4] {-1,1,0,0};
int dx[4] {0,0,-1,1};

int virusBFS()
{
    int answer = zero-WALL; //바이러스가 퍼지기 전 0의 개수(벽 3개 제외)
    queue<pair<int,int>> q;
    vector<vector<int>> virusmap(labmap);   //visited
    for(auto ele : virus) q.push(ele);

    while(!q.empty())
    {
        pair<int,int> v = q.front(); q.pop();
        //상하좌우 0이면 answer-1 하고 virusmap update
        for(int d = 0; d < 4; d++)
        {
            if(virusmap[v.first+dy[d]][v.second+dx[d]] == 0)
            {
                virusmap[v.first+dy[d]][v.second+dx[d]] = 2;
                --answer;
                q.push(make_pair(v.first+dy[d],v.second+dx[d]));
            }
        }
    }
    return answer;
}
void wallDFS(int cnt, int loc)
{
    if(cnt == 3)
    {   //bfs로 바이러스 퍼짐 체크
        // for(int i = 0; i < 5; i++)
        // {
        //     for(int j = 0; j < 5; j++)
        //         cout << labmap[i][j] << " ";
        //     cout << "\n";
        // }
        answer = max(answer,virusBFS());
        // cout << answer << "\n";
        return;
    }

    if(loc == N*M+1)  return;
    int row((loc-1)/M+1), col((loc-1)%M+1);
    if(labmap[row][col] != 0)   wallDFS(cnt, loc+1);    //해당 블록은 빈 칸이 아니므로 다음 칸
    else
    {
        //벽을 세우지 않음
        wallDFS(cnt, loc+1);
        //벽을 세움
        labmap[row][col] = 1;
        wallDFS(cnt+1, loc+1);
        labmap[row][col] = 0;
    }
}
int main()
{
    cin >> N >> M;
    for(int row = 1; row <= N; row++)
    {
        for(int col = 1; col <= M; col++)
        {
            cin >> labmap[row][col];
            if(labmap[row][col] == 2) virus.push_back(make_pair(row,col));
            else if(labmap[row][col] == 0) ++zero;
        }
    }
    //=========================================
    wallDFS(0,1);
    cout << answer << "\n";
}