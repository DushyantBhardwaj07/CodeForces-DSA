
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

class Solution {
public:
 std::vector<int> minimumTime(int n, std::vector<std::vector<int>>& edges, std::vector<int>& disappear) {
     // Create adjacency list
     std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;
     for (const auto& edge : edges) {
         int u = edge[0];
         int v = edge[1];
         int length = edge[2];
         adjList[u].push_back({v, length});
         adjList[v].push_back({u, length});
     }
     
     // Initialize priority queue for Dijkstra's algorithm
     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
     pq.push({0, 0}); // {distance from source, node}
     
     // Initialize minimum time array
     std::vector<int> minTime(n, -1);
     
     // Dijkstra's algorithm
     while (!pq.empty()) {
         auto [distance, node] = pq.top();
         pq.pop();
         
         if (minTime[node] != -1) continue; // Node already processed
         
         minTime[node] = distance;
         
         // Process neighbors
         for (const auto& neighbor : adjList[node]) {
             int nextNode = neighbor.first;
             int edgeLength = neighbor.second;
             
             if (minTime[nextNode] == -1) { // If neighbor hasn't been processed
                 if (disappear[nextNode] == -1 || distance + edgeLength < disappear[nextNode]) {
                     pq.push({distance + edgeLength, nextNode});
                 }
             }
         }
     }
     
     return minTime;
 }
};
