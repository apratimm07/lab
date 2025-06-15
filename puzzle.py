import heapq

N = 3
goal = [[1,2,3], [4,5,6], [7,8,0]]

dx = [0,0,-1,1]
dy = [-1,1,0,0]

def heuristic(board):
    total = 0
    for i in range(N):
        for j in range(N):
            value = board[i][j]
            goal_i = (value-1)//N
            goal_j = (value-1)%N
            total += abs(i-goal_i) + abs (j-goal_j)
    return total

def print_board(board):
    for row in board:
        print(*row)     
    print()
    
def best_first_search(start):
    #locate the initial position of 0
    for i in range(N):
        for j in range(N):
            if start[i][j] == 0:
                x,y = i,j
                
    pq = []
    heapq.heappush(pq, (heuristic(start), 0,start,x,y))
    visited = set()
    visited.add(str(start))
    
    while pq:
        h, depth, board, x,y = heapq.heappop(pq)
        print("Step:", depth, "| Heuristic:", h)
        print_board(board)
        
        if board == goal:
            print("Goal reached")
            return
        
        directions = [(0,-1), (0, 1), (-1, 0), (1, 0)]
        for move in directions:
            dx, dy = move
            nx = x+dx
            ny = y+dy
            
            if 0 <= nx < N and 0 <= ny < N:
                # Make a copy of board and swap tiles
                new_board = [row[:] for row in board]
                new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]

                # If not visited, add to queue
                key = str(new_board)
                if key not in visited:
                    visited.add(key)
                    heapq.heappush(pq, (heuristic(new_board), depth + 1, new_board, nx, ny))
        
# Try it with a sample puzzle
start = [[1, 2, 3], [4, 0, 5], [6, 7, 8]]
best_first_search(start)