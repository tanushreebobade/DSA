class Solution {
public:
    // Finds the starting index of the lexicographically largest suffix
    int bestStartingPoint(string &word, int n) {

        int i = 0; // Current best starting index
        int j = 1; // Candidate starting index

        while (j < n) {

            int k = 0; // Compare characters from both suffixes

            // Keep moving while both suffixes are equal
            while (i + k < n && j + k < n &&
                   word[i + k] == word[j + k]) {
                k++;
            }

            // If candidate suffix is larger, update best index
            if (j + k < n && word[j + k] > word[i + k]) {
                i = j;
                j++;
            }
            // Otherwise, skip all indices that cannot be the answer
            else {
                j += k + 1;
            }
        }

        return i;
    }

    string answerString(string word, int numFriends) {

        int n = word.size();

        // If there is only one friend, the whole string is the answer
        if (numFriends == 1)
            return word;

        // Find the best starting position
        int start = bestStartingPoint(word, n);

        // Maximum substring length we are allowed to take
        int longestLength = n - (numFriends - 1);

        // Remaining characters from the chosen start index
        int take = min(longestLength, n - start);

        // Return the required substring
        return word.substr(start, take);
    }
};