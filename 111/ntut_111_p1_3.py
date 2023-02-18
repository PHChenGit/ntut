def h(data):
    result = []
    length = len(data)
    for s in range(length):
        x = data[s] # problem 1-3-1
        y = data[0:s]+data[s+1:length] # problem 1-3-2, 1-3-3
        result = result + [x+y] # problem 1-3-4
    return result

output = h('ABCD')
for i in range(len(output)):
    print(output[i])