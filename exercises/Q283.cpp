/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]  1 0 3 12 0           
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]
 
提示:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        cout << nums.size() << endl;
        int index = 0;
        for(int i = 0;i < nums.size();i++){
            if (nums[i] != 0){
                nums[index] = nums[i];
                index +=1;
            }
        }

        for(int i = index;i < nums.size();i++){
            nums[i] = 0;
        }

        for(int i = 0;i < nums.size();i++){
            cout << nums[i] << endl;
        }
    }
};


int main(){
    vector<int> arr = {0};
    Solution s;
    s.moveZeroes(arr);

}