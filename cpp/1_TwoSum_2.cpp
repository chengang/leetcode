#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> v;
        std::unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            int want = target - nums[i];
            auto search_res = m.find(want);
            if (search_res != m.end()) {
                v.push_back(i);
                v.push_back(search_res->second);
                return v;
            }
            m.insert({nums[i], i});
        }
        v.push_back(999);
        v.push_back(999);
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
