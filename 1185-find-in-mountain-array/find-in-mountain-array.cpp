

class Solution {
public:
    

    int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int left = 0;
    int right = n - 1;

    // First, find the peak of the mountain (the maximum element).
    while (left < right) {
        int mid = left + (right - left) / 2;
        int midVal = mountainArr.get(mid);
        int nextVal = mountainArr.get(mid + 1);

        if (midVal < nextVal) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int peak = left;

    // Now, perform binary search in both the increasing and decreasing parts of the mountain array.
    int result = binarySearch(target, mountainArr, 0, peak, true);
    if (result != -1) {
        return result;
    }

    result = binarySearch(target, mountainArr, peak + 1, n - 1, false);
    return result;
}

int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool isIncreasing) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = mountainArr.get(mid);

        if (midVal == target) {
            return mid;
        } else if (midVal < target) {
            if (isIncreasing) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (isIncreasing) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

};