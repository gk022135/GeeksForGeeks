// traverse of matrix from down -> right->up -> left

#include<iostream>
#include<vector>

using namespace std;

class SpiralTraverse{
    public:
    vector<int> TraverseMatrix(vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<int>dir_r = {1,0,-1,0};
        vector<int>dir_c = {0,1,0,-1};

        int r = 0;
        int c = 0;

        int dir_pointer = 0;

        for(int i = 0; i<m*n; i++){
            res.push_back(mat[r][c]);
            visited[r][c] = true;

            int newR = r + dir_r[dir_pointer];
            int newC = c + dir_c[dir_pointer];

            if((newR>=0 && newR < m) && (newC >= 0 && newC<n) && !visited[newR][newC]){
                r = newR;
                c = newC;

            }
            else{
                dir_pointer = (dir_pointer + 1)%4;

                r = r + dir_r[dir_pointer];
                c = c + dir_c[dir_pointer];
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
    result = obj.TraverseMatrix(mat);

    for(int i : result) cout<<i<<", ";
    cout<<endl;

    return 0;

}