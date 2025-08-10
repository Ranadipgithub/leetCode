class Solution {
    Map<String, Boolean> memo = new HashMap<>();
    Map<Integer, Integer> posIndex = new HashMap<>();

    boolean solve(int[] stones, int n, int cs, int jump) {
        if (cs == stones[n - 1]) return true;
        String key = cs + "," + jump;
        if (memo.containsKey(key)) return memo.get(key);
        if (!posIndex.containsKey(cs) || jump <= 0) return false;

        boolean ans = solve(stones, n, cs + jump - 1, jump - 1)
                   || solve(stones, n, cs + jump, jump)
                   || solve(stones, n, cs + jump + 1, jump + 1);

        memo.put(key, ans);
        return ans;
    }

    public boolean canCross(int[] stones) {
        int n = stones.length;
        if (stones[1] != 1) return false;

        for (int i = 0; i < n; i++) {
            posIndex.put(stones[i], i);
        }

        return solve(stones, n, 1, 1);
    }
}
