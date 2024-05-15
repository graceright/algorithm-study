#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, maxVal;
vector<vector<int>> board(22,vector<int>(22,-1));
int dy[4] {-1,1,0,0};
int dx[4] {0,0,-1,1};   //상,하,좌,우
void move(vector<int> &direction)
{
    vector<vector<int>> boardtemp(board);
    for(int i = 0; i < 5; i++)
    {
        for(int step = 0; step < N; step++)
        {
            stack<int> s[N];
        }
    }
}
vector<int> genTo4(int k)
{   //들어온 10진수 k를 5개의 4진수 벡터로 반환
    vector<int> r(5);
    for(int i = 0; i < 5; i++)
    {
        r[i] = (k&3);   //하위 2bit만 가져와 저장   
        k >>= 2;        //하위 2bit는 사용했으니 shift
    }
    return r;
}
int main()
{
    cin >> N;
    for(int row = 1; row <= N; row++)
    {
        for(int col = 1; col <= N; col++)
            cin >> board[row][col];
    }
    //=============================================
    for(int k = 0; k < 1024; k++)   //모든 경우의 수 4^5 = 1024에 대해
    {
        vector<int> direction = genTo4(k);
        //실제로 이동 시뮬레이션
    }
}