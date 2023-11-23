#include<bits/stdc++.h>

using namespace std;

class FindSumPairs {
public:
    vector<int> arr1,arr2;
    unordered_map<int,int> mp1,mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int ele:arr1){
            mp1[ele]++;
        }
        for(int ele: arr2){
            mp2[ele]++;
        }
    }
    
    void add(int index, int val) {
        mp2[arr2[index]]--;
        arr2[index] += val;
        mp2[arr2[index]]++;
    }
    
    int count(int tot) {
        int count= 0;
        for(auto x: mp1){
            int rem = tot - x.first;
            if(mp2.find(rem)!=mp2.end()){
                count+=x.second*mp2[rem];
            }
        }
        return count;

    }
};
