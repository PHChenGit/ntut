def fib(n):
  data = [0 for i in range(0, n+1)]
  data[1] = 1
  for i in range(2, n+1):
    data[i] = data[i-1] + data[i-2]
  return data

def h(x):
  data = fib(x)
  for i in range(x):
    print(data[i], end=',')

h(8)