class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rl = 0;
        int cl = 0;
        int rr = matrix.size() - 1;
        int cr = matrix[0].size() - 1;
        
        if (target < matrix[rl][cl] || target > matrix[rr][cr]) return false;

        // run binary seatch on the first element of every row to figure out what row
        while (rl <= rr)
        {
            if (rl == rr) break;

            if (matrix[rl][cl] == target) return true;
            if (matrix[rr][cl] == target) return true;

            int rmid = rl + ((rr - rl) / 2);
            if (matrix[rmid][cl] == target) return true;

            if (target > matrix[rmid][cl])
            {
                if (target > matrix[rmid][cr])
                {
                    rl = rmid + 1;
                }
                else
                {
                    rl = rmid;
                    break;
                }
            }
            else if (target < matrix[rmid][cl])
            {
                rr = rmid - 1;
            }
        }
        cout << rl;

        while (cl <= cr)
        {
            if (matrix[rl][cl] == target) return true;
            if (matrix[rl][cr] == target) return true;

            int cmid = cl + ((cr - cl) / 2);
            if (matrix[rl][cmid] == target) return true;

            if (target > matrix[rl][cmid])
            {
                cl = cmid + 1;
            }
            else if (target < matrix[rl][cmid])
            {
                cr = cmid - 1;
            }
        }

        return false;

    }
};
