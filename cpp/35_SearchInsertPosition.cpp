#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int k=0; k<nums.size(); k++) {
            int v = nums[k];
            if (v >= target) {
                return k;
            }
        }
        return nums.size();
    }
};

int main() {
    std::vector<int> v = { 1,3,5,6 };
    int target = 5;

    Solution sn;
    int res = sn.searchInsert(v, target);
    std::cout << res ;

	std::cout << std::endl << "end" << std::endl ;
	return 0;
}
