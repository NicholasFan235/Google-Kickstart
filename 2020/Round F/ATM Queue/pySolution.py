from queue import PriorityQueue

T = int(input())
for t in range(1, T+1):
    N, X = [int(i) for i in input().split(' ')]
    queue = PriorityQueue()
    A = [int(i) for i in input().split(' ')]
    for n in range(N):
        loops = (A[n]-1)//X
        queue.put((loops*N+n, n+1))

    s = "Case #" + str(t) + ": "
    while not queue.empty():
        s += str(queue.get()[1]) + " "
    print(s)
    