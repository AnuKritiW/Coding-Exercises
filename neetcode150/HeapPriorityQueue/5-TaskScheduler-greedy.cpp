class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0); //a vector `count` initialised to 26 0s

        for (char task : tasks)
        {
            count[task - 'A']++; // track count of each char
        }

        sort(count.begin(), count.end()); // order doesn't matter
        int maxf = count[25];
        
        /*
        A _ _ A _ _ A
          gap   gap
        */
        // If the most frequent task appears maxf times, it creates (maxf - 1) gaps between its executions
        // Each gap must be at least n units apart
        // start by assuming all these gaps are idle
        int numIdles = (maxf - 1) * n;

        // fill the idle gaps using the remaining tasks
        // Each task can occupy at most one slot per gap, so it can reduce idle time by at most (maxf - 1)
        for (int i = 24; i >= 0; i--)
        {
            numIdles -= min(maxf - 1, count[i]);
        }

        return max(0, numIdles) + tasks.size();
    }
};
