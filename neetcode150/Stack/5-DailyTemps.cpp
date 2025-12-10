class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indicesSt;
        vector<int> result;

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while (!indicesSt.empty())
            {
                if (temperatures[indicesSt.top()] > temperatures[i])
                {
                    // if stack top is warmer than curr
                    result.insert(result.begin(), indicesSt.top() - i);
                    indicesSt.push(i);
                    break;
                }
                else
                {
                    indicesSt.pop();
                }
            }

            if (indicesSt.empty())
            {
                result.insert(result.begin(), 0);
                indicesSt.push(i);
            }
        }
        return result;
    }
};
