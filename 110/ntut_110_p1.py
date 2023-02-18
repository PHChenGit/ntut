def search(data, left, right, key):
  mid = (left+right)//2
  if data[mid] == key:
    return mid
  if left == right:
    return -1
  if data[mid] > key:
    return search(data, left, mid-1, key) # problem 1-4-1
  else:
    return search(data, mid+1, right, key) # problem 1-4-2

def f():
  data = [1, 5, 9, 14, 23, 26]
  my_dict = {}
  my_dict[9] = search(data, 0, 5, 9)
  my_dict[1] = search(data, 0, 5, 1)
  my_dict[14] = search(data, 0, 5, 14)
  print(my_dict) # problem 1-5-1
  print(data[1:5:2]) # problem 1-5-2, 第二個 : 代表每次的 step, so step = 2 代表 每次跳 2 個

f()