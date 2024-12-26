#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int max_water = 0;
    int left = 0, right = height.size() - 1;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        max_water = max(max_water, width * current_height);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area: " << maxArea(height1) << endl;

    vector<int> height2 = {1, 1};
    cout << "Max Area: " << maxArea(height2) << endl;

    return 0;
}
