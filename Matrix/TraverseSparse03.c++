// traversing a matrix such that top - bottom --> bottom - top so on...



//this problem is incomplete *

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

        vector<int>dir_r = {1,0,-1};
        vector<int>dir_c = {0,1,0};

        int r = 0;
        int c = 0;

        int dir_ptr  = 0;

        for(int i = 0;i<m*n; i++){
             res.push_back(mat[r][c]);
             visited[r][c] = true;

             int newR = r + dir_r[dir_ptr];
             int newC = c + dir_c[dir_ptr];

             if((newR>=0 &&newR < m) && (newC >= 0 && newC<m) && !visited[newR][newC]){
                r = newR;
                c = newC;
             }
             else{
                dir_ptr = (dir_ptr + 1)%3;
                
                r = r + dir_r[dir_ptr];
                c = c + dir_r[dir_ptr];
             }

        }
        return res;

    }
};

int main(){
    vector<vector<int>>mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int>result;

    SpiralTraverse obj;
    result = obj.TopDownTraverse(mat);

    for(int i : result) cout<<i<<", ";
    cout<<endl;

    return 0;

}