class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       
        vector<int> start_times;
        vector<int> end_times;
        
        for (int i = 0; i < intervals.size(); i++) {
            start_times.push_back(intervals[i][0]);
            end_times.push_back(intervals[i][1]);
        }
        
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());
        
        int s_ptr = 0;
        int e_ptr = 0;
        int num_rooms = 0;
        
        while (s_ptr < start_times.size() && e_ptr < end_times.size()) {
            if (start_times[s_ptr] >= end_times[e_ptr]) {
                num_rooms -= 1;
                e_ptr += 1;
            }
            num_rooms += 1;
            s_ptr += 1;
        }
        return num_rooms;
    }
};