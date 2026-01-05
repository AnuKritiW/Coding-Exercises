class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false;
        bool y = false;
        bool z = false;

        for (auto& triplet : triplets)
        {
            x |= (triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]);
            y |= (triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2]);
            z |= (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2]);
        }

        return (x && y && z);
    }
};
