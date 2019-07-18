def multiply(a, b):
    print("PY: Will compute", a, "times", b)
    c = 0
    for _ in range(0, a):
        c = c + b
    return c
