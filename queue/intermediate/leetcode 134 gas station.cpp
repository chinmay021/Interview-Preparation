//2 pass solution
class Solution
{
public
    int canCompleteCircuit(int[] gas, int[] cost)
    {
        //determine if we have a solution
        int total = 0;
        for (int i = 0; i < gas.length; i++)
        {
            total += gas[i] - cost[i];
        }
        if (total < 0)
        {
            return -1;
        }

        // find out where to start
        int tank = 0;
        int start = 0;
        for (int i = 0; i < gas.length; i++)
        {
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
}

//1 pass solution
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int curr_total = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            curr_total = curr_total + gas[i] - cost[i];
            total = total + gas[i] - cost[i];
            if (curr_total < 0)
            {
                start = i + 1;
                curr_total = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};