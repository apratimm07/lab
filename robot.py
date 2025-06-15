# Solve Robot (traversal) problem using means End Analysis

def move_towards_goal(start, goal, grid=(5, 5)):
    x, y = start
    gx, gy = goal
    path = [(x, y)]
    actions = []
    cost = 0

    while (x, y) != (gx, gy):
        if x < gx:
            x += 1
            actions.append("DOWN")
        elif x > gx:
            x -= 1
            actions.append("UP")
        elif y < gy:
            y += 1
            actions.append("RIGHT")
        elif y > gy:
            y -= 1
            actions.append("LEFT")

        path.append((x, y))
        cost += 1

    return path, actions, cost

# Run it
start = (0, 0)
goal = (3, 4)
path, steps, total = move_towards_goal(start, goal)

print("Path:", path)
print("Actions:", steps)
print("Total cost:", total)