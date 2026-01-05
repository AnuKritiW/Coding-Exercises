class Solution {
    unordered_map<string, vector<string>> adjList;
    int numTickets = 1;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // construct adj list
        for (const auto& ticket : tickets)
        {
            adjList[ticket[0]].push_back(ticket[1]);
            numTickets++;
        }

        // sort lexicographically
        for (auto& [key, value] : adjList)
        {
            if (value.size() > 1)
            {
                sort(value.begin(), value.end());
            }
        }

        string currAirport = "JFK";
        vector<string> route({currAirport});

        dfs(currAirport, route);
        return route;
    }

    bool dfs(const string& srcAirport, vector<string>& route)
    {
        if (route.size() == numTickets) return true;

        // if there is no further airport and we havent hit the target route yet
        if (adjList.find(srcAirport) == adjList.end()) return false;

        vector<string> nextAirports = adjList[srcAirport];
        for (int i = 0; i < nextAirports.size(); i++)
        {
            string currAirport = nextAirports[i];

            // remove the airport from the list because we are going to it
            adjList[srcAirport].erase(adjList[srcAirport].begin() + i);
            route.push_back(currAirport);

            if (dfs(currAirport, route)) return true;

            // insert it back at the same place because we couldn't find a suitable route
            adjList[srcAirport].insert(adjList[srcAirport].begin() + i, currAirport);
            route.pop_back();
        }
        return false;
    }
};
