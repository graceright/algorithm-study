//https://www.acmicpc.net/problem/16946
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int N,M,idx;
int dy[4] {-1,1,0,0};
int dx[4] {0,0,-1,1};

void bfs(vector<vector<int>> &board, pair<int,int> pos)
{   //인접한 0의 개수를 세고, 그 자리에 모두 개수로 채운다.
    queue<pair<int,int>> q;
    vector<pair<int,int>> zeroList;
    zeroList.push_back(pos);
    int cnt(0);
    q.push(pos);
    board[pos.first][pos.second] = 1;   //visited
    while(!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop(); cnt++;
        for(int d = 0; d < 4; d++)
        {
            pair<int,int> next = make_pair(cur.first+dy[d], cur.second+dx[d]);
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)    continue;   //out of board
            if(board[next.first][next.second] != 0) continue; //wall
            q.push(next);   zeroList.push_back(next);
            board[next.first][next.second] = 1; //visited
        }
    }
    cnt = (cnt%10) + (idx++)*10;
    //zeroList에 있는 좌표들을 cnt로 초기화
    for(auto e : zeroList)
    {
        board[e.first][e.second] = cnt;
    }

}
int main()
{
    cin >> N >> M;
    vector<vector<int>> answer(N,vector<int>(M));
    vector<pair<int,int>> walls;
    vector<vector<int>> board(N,vector<int>(M));    //첫째자리수 : 개수%10, ~둘째자리수 : 빈칸끼리의 고유 index
    for(int r = 0; r < N; r++)
    {
        string temp;
        cin >> temp;
        for(int c = 0; c < M; c++)
        {
            if(temp[c] == '1') 
            {
                board[r][c] = -1;
                walls.push_back(make_pair(r,c));
            }
        }
    }
    //============================================
    for(int r = 0; r < N; r++)  //board 선작업(탐색과정이 중복되므로)
    {
        for(int c = 0; c < M; c++)
        {
            if(board[r][c] == 0)
            {
                bfs(board, make_pair(r,c));
            }
        }
    }
    // for(auto a : board)
    // {
    //     for(auto b : a)
    //         cout << b << " ";
    //     cout << "\n";
    // }
    for(auto wall : walls)
    {
        int cnt(1);
        set<int> around;
        for(int d = 0; d < 4; d++)
        {
            pair<int,int> pos = wall;
            pos.first += dy[d];
            pos.second += dx[d];
            if(pos.first < 0 || pos.second < 0 || pos.first >= N || pos.second >= M) continue;  //out of board
            if(board[pos.first][pos.second] == -1) continue;    //wall
            around.insert(board[pos.first][pos.second]);
        }
        for(auto ele :around)   cnt += ele;
        answer[wall.first][wall.second] = cnt%10;
    }
    //============================================
    for(auto a : answer)
    {
        for(auto b : a)
            cout << b;
        cout << "\n";
    }
}