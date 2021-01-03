/*
You are given an array of distinct integers arr and an array of integer arrays pieces, 
where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. 
However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for(int i=0;i<pieces.size();++i){
            int j=0;
            for(;j<arr.size();j++)
                if(arr[j]==pieces[i][0])
                    break;
            
            if(j==arr.size())
                return false;
            j++;
            for(int k=1;k<pieces[i].size();k++,j++){
                if(j>=arr.size() || pieces[i][k]!=arr[j]){
                    cout<<i<<" "<<j<<" "<<k;
                    return false;
                }
            }
            
        }
        return true;
    }
};