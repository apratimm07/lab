# given 2 jugs: one with capacity of x and one with y.
# you need to measure exactly z litres of water using these 2 jugs
# allowed operations are: fill one of the jugs, empty one of the jugs
# and pour water from one to another until one is either full or empty

def water_jug_bfs(x, y, z):
    queue = [(0, 0)]  # Start with both jugs empty
    visited = set()
    parent = {}

    while queue:
        a, b = queue[0]
        queue = queue[1:]  # pop from front

        if (a, b) in visited:
            continue
        visited.add((a, b))

        # Check if solution is found
        if a == z or b == z or a + b == z:
            path = [(a, b)]
            while (a, b) in parent:
                a, b = parent[(a, b)]
                path.append((a, b))
            return path[::-1]

        # All possible moves
        moves = [
            (x, b),                  # Fill jug1
            (a, y),                  # Fill jug2
            (0, b),                  # Empty jug1
            (a, 0),                  # Empty jug2
            (a - min(a, y - b), b + min(a, y - b)),  # Pour jug1 -> jug2
            (a + min(b, x - a), b - min(b, x - a))   # Pour jug2 -> jug1
        ]

        for new_a, new_b in moves:
            if (new_a, new_b) not in visited:
                queue.append((new_a, new_b))
                parent[(new_a, new_b)] = (a, b)

    return []

# ---- User Input ----
x = int(input("Enter capacity of Jug 1: "))
y = int(input("Enter capacity of Jug 2: "))
z = int(input("Enter target amount: "))

# ---- Solve and Show Output ----
steps = water_jug_bfs(x, y, z)

if steps:
    print("\nSteps to measure", z, "litres:")
    for s in steps:
        print(s)
else:
    print("\nNo solution found.")