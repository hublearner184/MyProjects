/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30307
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(target == nums[i] + nums[j])
                {
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>{};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

