def solve(maximum, queue):
    q = {}
    p = PriorityQueue()
    output = []
    for i in range(len(queue)):
        turns = math.ceil(queue[i]/maximum)
        if turns in q:
            q[turns] = q[turns] + [i + 1]
        else:
            q[turns] = [i + 1]
    for key in q:
        p.put((key, q[key]))
    while not p.empty():
        item = p.get()[1]
        for i in item:
            output.append(str(i))
    return output