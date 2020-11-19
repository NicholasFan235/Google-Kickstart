t = int(input())
for x in range(1, t+1):
    s = "Case #" + str(x) + ": "
    n, c = [int(s) for s in input().split(" ")]
    p = [int(s) for s in input().split(" ")]

    a = 1
    np = []
    for y in p:
        y = [y, a]
        np.append(y)
        a += 1
    print(np)

    order = []
    while len(np) > 0:
        print(np)
        for z in np:
            z[0] = z[0] - c
            if z[0] <= 0:
                order.append(z[1])
                np.remove(z)

    for o in order:
        s += str(o) + " "


    print(s)