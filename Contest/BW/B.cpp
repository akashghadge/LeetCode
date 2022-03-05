class Solution
{
public:
    vector<int> map;
    int getMapping(int num)
    {
        vector<int> nums;
        if (num == 0)
            return map[0];

        int res = 0;
        long long mult = 1;
        while (num)
        {
            int digit = num % 10;
            int temp = map[digit];
            res += temp * mult;
            mult *= 10;
            num /= 10;
        }

        return res;
    }
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        map = mapping;
        int n = nums.size();
        vector<pair<int, int>> temp(n);
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = getMapping(nums[i]);
            temp[i] = {nums[i], i};
        }

        sort(temp.begin(), temp.end(), [arr](auto first, auto second)
             {
            int f=arr[first.second];
            int s=arr[second.second];

            if(f==s)
                return first.second < second.second;
            else
                return f < s; });

        int i = 0;
        for (auto val : temp)
        {
            nums[i] = val.first;
            i++;
        }
        return nums;
    }
};