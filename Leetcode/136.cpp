class Solution
{
public:
	int singleNumber(vector<int> &nums)
	{
		map<int, int> temp;

		for (int i = 0; i < nums.size(); i++)
		{
			int num = nums[i];
			map<int, int>::iterator iter = temp.find(num);
			if (iter == temp.end())
			{
				temp[num] = 1;
			}
			else
			{
				temp.erase(num);
			}
		}
		return temp.begin()->first;
	}
};
