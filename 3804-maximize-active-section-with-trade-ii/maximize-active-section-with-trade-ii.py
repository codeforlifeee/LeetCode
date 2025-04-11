K = 25
MAXN = int(1e5)
st = [[0] * MAXN for _ in range(K + 1)]

def build(array):
    n = len(array)
    for i in range(n):
        st[0][i] = array[i]
    for i in range(1, K + 1):
        for j in range(n - (1 << i) + 1):
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))])

def query(L, R):
    i = int(log(R - L + 1, 2))
    return max(st[i][L], st[i][R - (1 << i) + 1])

class Solution(object):
    def maxActiveSectionsAfterTrade(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        n = len(s)
        active = 0
        zero = []
        index = [-1] * n

        for i in range(n):
            if s[i] == '0':
                if i > 0 and s[i - 1] == '0':
                    zero[-1][1] += 1
                else:
                    zero.append([i, 1])
            else:
                active += 1
            index[i] = len(zero) - 1

        if not zero:
            return [active] * len(queries)

        gains = [0] * (len(zero) - 1)
        for i in range(len(zero) - 2, -1, -1):
            gains[i] = zero[i][1] + zero[i + 1][1]
        build(gains)

        res = [active] * len(queries)
        for q in range(len(queries)):
            L, R = queries[q]
            start = index[L] + 1
            end = index[R] - (s[R] == '0')
            cnt_left = -1 if index[L] == -1 else (zero[index[L]][1] - (L - zero[index[L]][0]))
            cnt_right = -1 if index[R] == -1 else (R - zero[index[R]][0] + 1)

            if start < end:
                res[q] = max(res[q], active + query(start, end - 1))
            if s[L] == '0' and s[R] == '0' and index[L] + 1 == index[R]:
                res[q] = max(res[q], active + cnt_left + cnt_right)
            if s[L] == '0' and index[L] + 1 < index[R] + (s[R] == '1'):
                res[q] = max(res[q], active + cnt_left + zero[index[L] + 1][1])
            if s[R] == '0' and index[L] < index[R] - 1:
                res[q] = max(res[q], active + cnt_right + zero[index[R] - 1][1])
        return res