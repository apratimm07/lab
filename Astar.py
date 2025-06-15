import heapq

def a_star(graph, h, start, goal):
    queue = [(h[start], 0, start, [start])]  # (f = g + h, g, current, path)
    visited = set()

    while queue:
        f, g, node, path = heapq.heappop(queue)

        if node == goal:
            return path, g

        if node in visited:
            continue
        visited.add(node)

        for next_node, cost in graph.get(node, []):
            if next_node not in visited:
                g_new = g + cost
                f_new = g_new + h[next_node]
                heapq.heappush(queue, (f_new, g_new, next_node, path + [next_node]))

    return [], float('inf')

# Simple graph
graph = {
    'A': [('B', 2), ('C', 1)],
    'B': [('D', 3), ('E', 2)],
    'C': [('D', 2)],
    'D': [('G', 1)],
    'E': [('G', 5)]
}

# Heuristic values
h = {
    'A': 6,
    'B': 4,
    'C': 5,
    'D': 2,
    'E': 3,
    'G': 0
}

# Run
path, total = a_star(graph, h, 'A', 'G')
print("Path:", " -> ".join(path))
print("Cost:", total)