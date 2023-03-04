/*
1886. Determine Whether Matrix Can Be Obtained By Rotation
Easy
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // the method of rotating array to 90 degree is transpose and reverse the each part 
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0;i<n;++i)
            for(int j=i;j<n;j++)
                swap(mat[i][j] , mat[j][i]); 
        
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<3;++i){ // rotate 3 times 0 -> 90 -> 180 -> 270 
            rotate(mat);
            if(mat == target){
                return true;
            }
        }
        return false;
    }
};