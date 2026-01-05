class Solution {
    unordered_map<int, vector<int>> prereqMap;
    unordered_set<int> currVisiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++)
        {
            // initialise
            prereqMap[i] = {};
        }

        for (auto prereq : prerequisites)
        {
            prereqMap[prereq[0]].push_back(prereq[1]);
        }

        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course)) return false;
        }

        return true;
    }

    bool dfs(int course)
    {
        // cycle found
        auto foundIter = currVisiting.find(course);
        if (foundIter != currVisiting.end()) return false;

        if (prereqMap[course].empty()) return true;

        currVisiting.insert(course);
        for (int neighbor : prereqMap[course])
        {
            if (!dfs(neighbor)) return false;
        }

        currVisiting.erase(course);
        prereqMap[course].clear();

        return true;
    }
};
