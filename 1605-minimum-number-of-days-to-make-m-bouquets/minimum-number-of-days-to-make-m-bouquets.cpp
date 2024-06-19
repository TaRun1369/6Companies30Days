class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) return true;
        }
        
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();

        // long long lund = m*k*1ll;
        if(m > 1e3 && k > 1e3) return -1;

        if (n < m * k*1ll) return -1;
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};