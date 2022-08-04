#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> v;
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums.size(); j++) {
                if (i!=j && target == nums[i] + nums[j]) {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        v.push_back(0);
        v.push_back(1);
        return v;
    }
};

int main() {
    std::vector<int> v = { 3,2,4 };

    Solution sn;
    std::vector<int> res = sn.twoSum(v, 6);
    for( int n : res) {
        std::cout << n << ",";
    }

	std::cout << std::endl << "end" << std::endl ;
	return 0;
}
