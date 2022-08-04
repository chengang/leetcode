#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        long i = 1;
        while (i<=x) {
            if (i*i > x) {
                return i-1;
            }
            i++;
        }
        return -1;
    }
};

int main() {
    int x = 8;

    Solution sn;
    int res = sn.mySqrt(x);
    std::cout << res ;

	std::cout << std::endl << "end" << std::endl ;
	return 0;
}
