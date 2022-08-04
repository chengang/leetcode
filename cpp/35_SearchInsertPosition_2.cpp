#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = (high - low ) / 2 + low;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
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
