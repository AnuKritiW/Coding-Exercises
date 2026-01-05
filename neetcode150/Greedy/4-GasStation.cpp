class Solution {
public:
    int getTank(vector<int>& gas, vector<int>& cost, int idx) {
        return gas[idx] - cost[idx];
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int numStations = gas.size();

        // we start wrapping around the stations
        int start = numStations - 1;
        int end = 0;

        int tank = getTank(gas, cost, start);

        while (start > end)
        {
            if (tank < 0)
            {
                start--;
                tank += getTank(gas, cost, start);
            }
            else // tank >= 0 i.e. segment so far is feasible
            {
                tank += getTank(gas, cost, end);
                end++;
            }
        }

        return ((tank >= 0) ? start : -1);
    }
};
