/*
Given a matrix mat[][] of size m x n, the task is to print all elements of the matrix in spiral form.
*/

#include<iostream>
#include<vector>

using namespace std;

class SpiralTraverse{
    public:
    vector<int> spiralTravesreMat(vector<vector<int>> &mat){
        vector<int>res;
        int m = mat.size();
        int n = mat[0].size();

        vector<int>dir_r = {0,1,0,-1};   //right(0), down(1), left(0), up(-1) //the seqquence of order decide by question where we have to move first
        vector<int>dir_c = {1,0,-1,0};

        vector<vector<bool>>visted(m, vector<bool>(n,false)); // initiall all value of visited matrix is set to be false

        int r = 0;
        int c = 0;
        int dir_point = 0;

        for(int i =0; i<m*n; i++){
            res.push_back(mat[r][c]);

            visted[r][c] = true;

            int newR = r + dir_r[dir_point];
            int newC = c + dir_c[dir_point];

            if((newR>=0 && newR<m) && (newC>=0 && newC<n) && !visted[newR][newC]){
                r = newR;
                c = newC;


            }
            else {

            // Change direction (turn clockwise)
            dir_point = (dir_point + 1) % 4;

            r += dir_r[dir_point];
            c += dir_c[dir_point];
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
    result = obj.spiralTravesreMat(mat);
    for(int i : result) cout<<i<<", ";
    cout<<endl;

    return 0;
}