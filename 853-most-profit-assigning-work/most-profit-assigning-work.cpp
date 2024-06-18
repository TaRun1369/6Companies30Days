class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        // Create pairs of difficulty and profit, and sort them by difficulty
        vector<pair<int, int>> jobs;
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({d[i], p[i]});
        }
        sort(jobs.begin(), jobs.end());

        // Sort the workers by their abilities
        sort(w.begin(), w.end());

        // Iterate through the jobs and assign the maximum possible profit to each worker
        int maxProfit = 0, ans = 0, j = 0;
        for (int i = 0; i < w.size(); ++i) {
            while (j < n && w[i] >= jobs[j].first) {
                maxProfit = max(maxProfit, jobs[j].second);
                ++j;
            }
            ans += maxProfit;
        }

        return ans;
    }
};