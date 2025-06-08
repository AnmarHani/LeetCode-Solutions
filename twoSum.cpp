class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> hashmap;

        vector<int> result;

        for(size_t i = 0; i < nums.size(); i++)
            hashmap[nums[i]] = i;


        for(size_t i = 0; i < nums.size(); i++){
            // Check if the target - current_num = result is present in the map, if yes, return the [current_num_idx, the_hashmap_idx]
            if(hashmap.find(target - nums[i]) != hashmap.end() && hashmap[target - nums[i]] != i) {
                result.push_back(i);
                result.push_back(hashmap[target - nums[i]]);
                break;
            }
        }

        return result;
    }
};
