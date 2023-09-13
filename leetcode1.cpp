#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int mod=1e+7;
vector<pair<int,int>> dirs8={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};//上下左右四个方向
#define all(c) (c).begin(), (c).end()

class Solution {
public:
    vector<pair<int,int>> dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> idx(n*n,vector<int>(2));
        set<pair<int,int>> s(all(dir));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int& index=grid[i][j];
                idx[index]={i,j};
            }
        }
        if(idx[0]!=vector<int>{0,0})   return false;
        for(int i=1;i<n*n;++i){
            int dx=(idx[i][0]-idx[i-1][0]);
            int dy=(idx[i][1]-idx[i-1][1]);
            auto t=make_pair(dx,dy);
            if(!s.count(t)) return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int>> grid={{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    Solution s;
    cout<<s.checkValidGrid(grid);
    return 0;
}
