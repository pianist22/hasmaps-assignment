#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int ele:arr){
            mp[ele]++;
        }
        int count = 0; 
        for(int i=0;i<arr.size();i++){
            int rem = k-arr[i];
            if(rem == arr[i]){
                if(mp[rem]>=2){                
                    count++;
                    mp[rem] = mp[rem]-2;
                }
            }
            else{
                if(mp.find(rem)!=mp.end()){
                    if(mp[rem]>0 && mp[arr[i]]>0){
                        count++;
                        mp[rem]--;
                        mp[arr[i]]--;
                    }
                }
            }
        }
        return count;
    }
};