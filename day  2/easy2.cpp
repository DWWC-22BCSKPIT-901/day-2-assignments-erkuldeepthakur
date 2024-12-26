#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }

    return k;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);

    cout << "Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    }
    cout << "]" << endl;

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);

    cout << "Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}
