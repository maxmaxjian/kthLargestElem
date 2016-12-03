// // O(n) solution
// #include <iostream>
// #include <vector>
// #include <algorithm>

// class solution {
// public:
//     int findKthLargest(const std::vector<int> & nums, int k) {
// 	auto mmpair = std::minmax_element(nums.begin(), nums.end());
// 	int min = *mmpair.first, max = *mmpair.second;
// 	std::vector<int> buckets(max-min+1, 0);
// 	for (auto & n : nums)
// 	    buckets[n-min]++;

// 	int rtn;
// 	for (size_t i = buckets.size()-1; i < buckets.size();) {
// 	    if (k > 0) {
// 		if (buckets[i] > 0) {
// 		    k--;
// 		    buckets[i]--;
// 		    rtn = i+min;
// 		}
// 		else
// 		    i--;
// 	    }
// 	    else
// 		return rtn;
// 	}
//     }
// };

// O(nlog(n)) solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class solution {
public:
    int findKthLargest(const std::vector<int> & nums, int k) {
	auto cpy = nums;
	std::sort(cpy.begin(), cpy.end(), std::greater<int>());
	return cpy[k-1];
    }
};

int main() {
    std::vector<int> nums{3,2,1,5,6,6,4};
    int k = 3;
    
    solution soln;
    std::cout << "The " << k << "th largest element is:\n"
	      << soln.findKthLargest(nums, k) << std::endl;
}
