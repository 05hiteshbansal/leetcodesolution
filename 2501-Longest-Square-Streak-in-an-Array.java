class Solution {
    public int longestSquareStreak(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        mp.put(nums[0], 1);

        for (int i = 1; i < n; i++) {
            int no = (int) Math.sqrt(nums[i]);
            if (no * no == nums[i] && mp.containsKey(no)) {  // Check if it's a perfect square and exists in map
                int temp = mp.get(no);
                mp.put(nums[i], temp + 1);
            } else {
                mp.put(nums[i], 1);
            }
        }

        int ans = mp.values().stream().max(Integer::compare).orElse(1);

    
        

        return ans == 1 ? -1 : ans;
    }
}