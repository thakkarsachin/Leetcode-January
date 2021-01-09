/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int in=0,n=1;
        vector<int> vc;
        
        for(;in<arr.size();){
            if(arr[in]!=n){
                vc.push_back(n);
            }else{
                in++;
            }
            n++;
        }
        
        while(vc.size()<k){
            vc.push_back(n++);
        }
        
        return vc[k-1];
    }
};