# Graph


Graph is probably the data structure that has the closest resemblance to our daily life. There are many types of graphs describing the relationships in real life. For instance, our friend circle is a huge “graph”.

### Example in Real Life
social graph of friendship

There are many types of “graphs”. In this Explore Card, we will introduce three types of graphs: undirected graphs, directed graphs, and weighted graphs.

- Undirected graphs
- Directed graphs
- Weighted graphs


#### Undirected Graphs

The edges between any two vertices in an “undirected graph” do not have a direction, indicating a two-way relationship.
![Undirected graphs](/public/Undirectedgraphs.png)


#### Directed Graphs

The edges between any two vertices in a “directed graph” graph are directional.
![Directed graph](/public/Directedgraphs.png)


#### Weighted Graphs

Each edge in a “weighted graph” has an associated weight. The weight can be of any metric, such as time, distance, size, etc. The most commonly seen “weighted map” in our daily life might be a city map. In Figure 3, each edge is marked with the distance, which can be regarded as the weight of that edge.
![Weighted graphs](/public/Weightedgraphs.png)


#### Path
a path in a graph is a finite or infinite sequence of edges which joins a sequence of vertices which, by most definitions, are all distinct

#### Degree of a node in an undirected graph
is the number of edges incident on it  and total degree of graph is twice the number  G = 2 * E

### The Definition of “graph” and Terminologies

“Graph” is a non-linear data structure consisting of vertices and edges. There are a lot of terminologies to describe a graph. If you encounter an unfamiliar term in the following Explore Card, you may look up the definition below.

- Vertex: In Figure 1, nodes such as A, B, and C are called vertices of the graph.
- Edge: The connection between two vertices are the edges of the graph. In Figure 1, the connection between person A and B is an edge of the graph.
- Path: the sequence of vertices to go through from one vertex to another. In Figure 1, a path from A to C is [A, B, C], or [A, G, B, C], or [A, E, F, D, B, C]. <br/>
  **Note**: there can be multiple paths between two vertices.
- Cycle: a path where the starting point and endpoint are the same vertex. In Figure 1, [A, B, D, F, E] forms a cycle. Similarly, [A, G, B] forms another cycle.
- Negative Weight Cycle: In a “weighted graph”, if the sum of the weights of all edges of a cycle is a negative value, it is a negative weight cycle. In Figure 4, the sum of weights is -3.
- Connectivity: if there exists at least one path between two vertices, these two vertices are connected. In Figure 1, A and C are connected because there is at least one path
- Degree of a Vertex: the term “degree” applies to unweighted graphs. The degree of a vertex is the number of edges connecting the vertex. In Figure 1, the degree of vertex A is 3 because three edges are connecting it.
- In-Degree: “in-degree” is a concept in directed graphs. If the in-degree of a vertex is d, there are d directional edges incident to the vertex. In Figure 2, A’s indegree is 1, i.e., the edge from F to A.
- Out-Degree: “out-degree” is a concept in directed graphs. If the out-degree of a vertex is d, there are d edges incident from the vertex. In Figure 2, A’s outdegree is 3, i,e, the edges A to B, A to C, and A to G.


#### Traverse Graph

1. Using DFS Recursive Solution

```c++
 void dfsPrint(const vector<vector<int>>& graph, int sourceNode) {
    cout << sourceNode << endl;
    for (int neighbor : graph[sourceNode]) {
        dfsPrint(graph, neighbor);
    }
}
```

2. Using DFS With Stack

```c++
void dfsPrint(const vector<vector<int>>& graph, int sourceNode) {
    stack<int> s;
    s.push(sourceNode);

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << endl;

        for (int neighbor : graph[current]) {
            s.push(neighbor);
        }
    }
}
```

3. Using BFS With Queue

```c++
void bfs(const vector<vector<int>>& graph, int sourceNode) {
    queue<int> q;
    q.push(sourceNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << endl;

        for (int neighbor : graph[current]) {
            q.push(neighbor);
        }
    }
}
```


### Starting WITH GRAPH Problems

- Has Path Problem Check if Graph Has Path From Source >>> Destination
```c++

#include <vector>
#include <stack>

bool hasPathDfsStack(const std::vector<std::vector<int>>& graph, int src, int dest) {
  std::stack<int> stack;
  stack.push(src);

  while (!stack.empty()) {
    int currentNode = stack.top();
    stack.pop();
    if (currentNode == dest) {
      return true;
    }

    for (int neighbor : graph[currentNode]) {
      stack.push(neighbor);
    }
  }

  return false;
}
```

```c++


const hasPathUsingBFS = (graph, src, dest) => {
  const queue = [src];

  while (queue.length > 0) {
    const currentNode = queue.shift();

    if (currentNode === dest) {
      return true;
    }

    for (const neighbor of graph[currentNode]) {
      queue.push(neighbor);
    }
  }

  return false;
};
```

```c++
#include <vector>

bool hasPath(const std::vector<std::vector<int>>& graph, int src, int dest) {
  if (src == dest) {
    return true;
  }

  for (int neighbor : graph[src]) {
    if (hasPath(graph, neighbor, dest) == true) {
      return true;
    }
  }

  return false;
}
```

- Undirected Graph Hash Path Problem **Mark Visited**

```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool DFShasPath(const std::unordered_map<int, std::vector<int>>& graph, int src, int dest, std::unordered_set<int>& visited) {
  if (src == dest) {
    return true;
  }
  if (visited.count(src)) {
    return false;
  }

  visited.insert(src);

  for (int neighbor : graph.at(src)) {
    if (DFShasPath(graph, neighbor, dest, visited)) {
      return true;
    }
  }

  return false;
}

bool undirectedPathUsingDFSRecursive(const std::vector<std::vector<int>>& edges, int source, int dest) {
  std::unordered_map<int, std::vector<int>> graph;
  for (const auto& edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }

  std::unordered_set<int> visited;
  return DFShasPath(graph, source, dest, visited);
}
```

- Connected Component Problem

```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool dfs(const std::unordered_map<int, std::vector<int>>& graph, int currentNode, std::unordered_set<int>& visited) {
  if (visited.count(currentNode)) {
    return false;
  }

  visited.insert(currentNode);

  for (int neighbor : graph.at(currentNode)) {
    dfs(graph, neighbor, visited);
  }

  return true;
}

int connectedComponentCount(const std::unordered_map<int, std::vector<int>>& graph) {
  std::unordered_set<int> visited;
  int counter = 0;

  for (const auto& pair : graph) {
    int node = pair.first;
    if (dfs(graph, node, visited)) {
      counter++;
    }
  }

  return counter;
}
```

- Largest Component

```c++

#include <vector>
#include <unordered_map>
#include <unordered_set>

int exploreGrahs(const std::unordered_map<int, std::vector<int>>& graph, int node, std::unordered_set<int>& visited) {
  if (visited.count(node)) {
    return 0;
  }
  visited.insert(node);

  int size = 1;
  for (int neighbor : graph.at(node)) {
    size += exploreGrahs(graph, neighbor, visited);
  }

  return size;
}

int largestComponent(const std::unordered_map<int, std::vector<int>>& graph) {
  std::unordered_set<int> visited;
  int largestSize = 0;

  for (const auto& pair : graph) {
    int node = pair.first;
    int size = exploreGrahs(graph, node, visited);
    if (size != 0) {
      largestSize = std::max(largestSize, size);
    }
  }

  return largestSize;
}
```

- Shortest Path
  
```c++

#include <vector>
#include <unordered_map>
#include <queue>

int shortestPath(const std::vector<std::vector<int>>& edges, int nodeA, int nodeB) {
  std::unordered_set<int> visited;
  std::queue<std::pair<int, int>> queue;
  queue.push({nodeA, 0});
  std::unordered_map<int, std::vector<int>> graph = buildGraph(edges);

  while (!queue.empty()) {
    int currentNode = queue.front().first;
    int distance = queue.front().second;
    queue.pop();

    if (visited.count(currentNode)) {
      continue;
    }
    visited.insert(currentNode);

    if (currentNode == nodeB) {
      return distance;
    }

    for (int neighbor : graph[currentNode]) {
      queue.push({neighbor, distance + 1});
    }
  }

  return -1;
}

std::unordered_map<int, std::vector<int>> buildGraph(const std::vector<std::vector<int>>& edges) {
  std::unordered_map<int, std::vector<int>> graph;
  for (const auto& edge : edges) {
    int a = edge[0];
    int b = edge[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  return graph;
}
```

- Island Count

```c++
#include <vector>
#include <unordered_set>
#include <string>

bool dfs(const std::vector<std::vector<char>>& grid, std::unordered_set<std::string>& visited, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] == 'W' || visited.count(std::to_string(row) + '-' + std::to_string(col))) {
    return false;
  }

  visited.insert(std::to_string(row) + '-' + std::to_string(col));

  dfs(grid, visited, row + 1, col);
  dfs(grid, visited, row - 1, col);
  dfs(grid, visited, row, col + 1);
  dfs(grid, visited, row, col - 1);

  return true;
}

int islandCount(const std::vector<std::vector<char>>& grid) {
  std::unordered_set<std::string> visited;
  int islandCounter = 0;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (dfs(grid, visited, i, j)) {
        islandCounter++;
      }
    }
  }

  return islandCounter;
}
```
- Minimum Island (GRID Graphs)
  
```c++
#include <vector>
#include <unordered_set>
#include <string>
#include <climits>

int dfs(const std::vector<std::vector<char>>& grid, std::unordered_set<std::string>& visited, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] == 'W' || visited.count(std::to_string(row) + '-' + std::to_string(col))) {
    return 0;
  }

  visited.insert(std::to_string(row) + '-' + std::to_string(col));

  int size = 1;
  size += dfs(grid, visited, row + 1, col);
  size += dfs(grid, visited, row - 1, col);
  size += dfs(grid, visited, row, col + 1);
  size += dfs(grid, visited, row, col - 1);

  return size;
}

int minimumIsland(const std::vector<std::vector<char>>& grid) {
  std::unordered_set<std::string> visited;
  int minimumIslandSize = INT_MAX;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      int size = dfs(grid, visited, i, j);
      if (size != 0) {
        minimumIslandSize = std::min(size, minimumIslandSize);
      }
    }
  }

  return minimumIslandSize == INT_MAX ? 0 : minimumIslandSize;
}
```




