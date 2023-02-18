def g(N):
    for i in range(2, N):
        if N % 2 == 0: # problem 1-2-1
            return False
    return True # problem 1-2-2

def f(N):
    data = [i for i in range(2, N) if g(i) == True] # problem 1-2-3, 1-2-4
    return data # problem 1-2-5

res = f(20)

for i in range(len(res)):
    print(res[i], end=' ')