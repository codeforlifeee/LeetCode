#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    long long safeChoose(int total, int count) {
        if (count < 0 || count > total) return 0;
        if (count == 0 || count == total) return 1;
        if (count > total - count) {
            count = total - count;
        }
        long long combinations = 1;
        for (int i = 1; i <= count; ++i) {
            long long multiplier = total - i + 1;
            if (combinations > LLONG_MAX / multiplier) {
                return LLONG_MAX;
            }
            combinations = (combinations * multiplier) / i;
        }
        return combinations;
    }

    long long getPermutationCount(const vector<int>& frequencies) {
        int total_remaining = 0;
        for (int count : frequencies) {
            total_remaining += count;
        }
        long long total_permutations = 1;
        for (int count : frequencies) {
            if (count == 0) continue;
            long long ways = safeChoose(total_remaining, count);
            if (ways == LLONG_MAX || total_permutations > LLONG_MAX / ways) {
                return LLONG_MAX;
            }
            total_permutations *= ways;
            total_remaining -= count;
        }
        return total_permutations;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> char_counts(26, 0);
        for (char character : s) {
            char_counts[character - 'a']++;
        }

        int odd_count_characters = 0;
        int odd_char_index = -1;
        vector<int> half_frequencies(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (char_counts[i] % 2 != 0) {
                odd_count_characters++;
                odd_char_index = i;
            }
            half_frequencies[i] = char_counts[i] / 2;
        }

        if (odd_count_characters > 1) {
            return "";
        }

        long long total_possible = getPermutationCount(half_frequencies);
        if (total_possible < k) {
            return "";
        }

        int half_length = 0;
        for (int count : half_frequencies) {
            half_length += count;
        }

        string first_half = "";
        long long current_rank = k;

        for (int step = 0; step < half_length; ++step) {
            for (int candidate_char = 0; candidate_char < 26; ++candidate_char) {
                if (half_frequencies[candidate_char] == 0) continue;

                half_frequencies[candidate_char]--;
                long long remaining_permutations = getPermutationCount(half_frequencies);

                if (current_rank <= remaining_permutations) {
                    first_half += (char)('a' + candidate_char);
                    break;
                } else {
                    current_rank -= remaining_permutations;
                    half_frequencies[candidate_char]++;
                }
            }
        }

        string middle_character = "";
        if (odd_char_index != -1) {
            middle_character += (char)('a' + odd_char_index);
        }

        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        return first_half + middle_character + second_half;
    }
};
