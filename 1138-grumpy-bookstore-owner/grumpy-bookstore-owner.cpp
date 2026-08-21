class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        vector<int>& arr = customers;
        int n = arr.size();
        int prev = 0;
        int curr = 0;
        int idx = 0;

        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1)
                prev += arr[i];
        }
        int maxL = prev;

        // sliding window
        int i = 1, j = k;
        while (j < n) {
            curr = prev;
            if (grumpy[j] == 1)
                curr += arr[j];
            if (grumpy[i - 1] == 1)
                curr -= arr[i - 1];

            if (maxL < curr) {
                maxL = curr;
                idx = i;
            }
            prev = curr;

            i++;
            j++;
        }

        for (int i = idx; i < idx + k; i++) {
            grumpy[i] = 0;
        }

        int maxS = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                maxS += arr[i];
        }

        return maxS;
    }
};