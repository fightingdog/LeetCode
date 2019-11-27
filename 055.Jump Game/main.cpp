//
//  main.cpp
//  Jump Game
//
//  Created by 刘昭 on 2019/11/27.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curLongestPosition = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > curLongestPosition) {
                return false;
            }
            curLongestPosition = max(curLongestPosition, i + nums[i]);
        }
        return true;
    }
    
    bool canJump1(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i++) {
//            for (int j = 0; j < i; j++) {  这么写在遇到[1,1,1,...]会超时
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,1,4};
    Solution so = Solution();
    bool ret = so.canJump1(nums);
    cout << ret << endl;
    return 0;
}
