/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. 
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int res = m+n-1;
        m--;
        n--;
        
        while(m>=0 && n>=0){
            if(nums1[m]>nums2[n])
                nums1[res--]=nums1[m--];
            else
                nums1[res--]=nums2[n--];
        }
        while(n>=0){
            nums1[res--]=nums2[n--];
        }
    }
};