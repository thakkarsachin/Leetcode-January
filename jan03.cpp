/*
Suppose you have n integers from 1 to n. We define a beautiful arrangement as an array that is constructed by 
these n numbers successfully if one of the following is true for the ith position (1 <= i <= n) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Given an integer n, return the number of the beautiful arrangements that you can construct.
*/

class Solution {
public:
    int res = 0;
    void swap(vector<int>& arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void permute(vector<int> &arr, int idx) {
        if (idx == arr.size())
            res++;
        for (int i = idx; i < arr.size(); i++) {
            swap(arr, i, idx);
            if (arr[idx]%(idx+1) == 0 || (idx+1)%arr[idx] == 0)
                permute(arr, idx+1);
            swap(arr, i, idx);
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++) {
            arr[i-1] = i;
        }
        permute(arr, 0);
        return res;
    }
};