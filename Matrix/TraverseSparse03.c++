// traversing a matrix such that top - bottom --> bottom - top so on...


#include<iostream>
#include<vector>

using namespace std;

class SpiralTraverse{
    public:
    vector<int> TopDownTraverse(vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>>visited(m, vector<bool>(m,false));
        vector<int>res;

        vector<int>dir_r = {1,-1};
        vector<int>dir_c = {0,0};

        int r = 0;
        int c = 0;

        int dir_ptr  = 0;

        for(int i = 0;i<m*n; i++){
             res.push_back(mat[r][c]);
             visited[r][c] = true;
             
        }




    }
};