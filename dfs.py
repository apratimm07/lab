# given 2 jugs: one with capacity of x and one with y.
# you need to measure exactly z litres of water using these 2 jugs
# allowed operations are: fill one of the jugs, empty one of the jugs
# and pour water from one to another until one is either full or empty

def water_jug_dfs(x, y, z):
    visited = set()
    path = []

    def dfs(j1, j2):
        if (j1, j2) in visited:
            return False

        visited.add((j1, j2))
        path.append((j1, j2))

        # Check if we have reached the target
        if j1 == z or j2 == z or j1 + j2 == z:
            return True

        # All possible moves
        moves = [
            (x, j2),              # Fill jug1
            (j1, y),              # Fill jug2
            (0, j2),              # Empty jug1
            (j1, 0),              # Empty jug2
            (j1 - min(j1, y - j2), j2 + min(j1, y - j2)),  # Pour jug1 -> jug2
            (j1 + min(j2, x - j1), j2 - min(j2, x - j1))   # Pour jug2 -> jug1
        ]

        for new_j1, new_j2 in moves:
            if dfs(new_j1, new_j2):
                return True

        path.pop()  # Backtrack
        return False

    found = dfs(0, 0)
    if found:
        return path
    else:
        return []

# ---- User Input ----
x = int(input("Enter capacity of Jug 1: "))
y = int(input("Enter capacity of Jug 2: "))
z = int(input("Enter target amount: "))

steps = water_jug_dfs(x, y, z)

if steps:
    print("\nSteps to measure", z, "litres:")
    for s in steps:
        print(s)
else:
    print("\nNo solution found.")