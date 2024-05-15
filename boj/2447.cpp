//https://www.acmicpc.net/problem/2447
#include <cstdio>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

long long N;

void solve(vector<vector<char>> & stars, long long size, long long row, long long col)
{
    // printf("[%s]%lld r:%lld c:%lld\n",__func__,size,row,col);
    if(size == 0)   return;
    size /= 3;
    //빈칸 찍기
    for(long long r = row + size; r < row+size*2; r++)
    {
        for(long long c = col + size; c < col+size*2; c++)
        {
            // printf("*-> :%lld %lld\n",r,c);
            stars[r][c] = ' ';
        }
    }
    for(long long r = row; r < row + size*3; r+=size)
    {
        for(long long c = col; c < col + size*3; c+=size)
        {
            solve(stars, size, r, c);
        }
    }
}

int main()
{
    scanf("%lld", &N);
    //===========================
    vector<vector<char>> stars(N,vector<char>(N,'*'));
    solve(stars, N, 0, 0);
    //===========================
    for(auto a : stars)
    {
        for(auto b : a)
            printf("%c",b);
        printf("\n");
    }
}