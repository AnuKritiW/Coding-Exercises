class Solution {
public:

    void sort_by_first_vec(vector<int>& position, vector<int>& speed)
    {

        vector<pair<int, int>> pairVec;
        pairVec.reserve(position.size());
        for (int i = 0; i < position.size(); ++i)
        {
            pairVec.emplace_back(position[i], speed[i]);
        }

        sort(pairVec.begin(), pairVec.end(), [](const auto& x, const auto& y){return x.first<y.first;});

        for (int i = 0; i < pairVec.size(); ++i)
        {
            position[i] = pairVec[i].first;
            speed[i] = pairVec[i].second;
        }
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        sort_by_first_vec(position, speed);

        float currMaxTime = -1.0;
        int numFleets = 0;
        for (int i = position.size() - 1; i >= 0; --i)
        {
            int currPos = position[i];
            int currSpeed = speed[i];
            float currTime = (static_cast<float>(target) - currPos) / currSpeed;

            if (currTime > currMaxTime)
            {
                numFleets++;
                currMaxTime = currTime;
            }
        }
        return numFleets;
    }
};
