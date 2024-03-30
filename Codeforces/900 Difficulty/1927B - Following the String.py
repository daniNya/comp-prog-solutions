for _ in range(int(input())):
  input()

  res = ""
  lst = [[chr(ord('a') + n) for n in range(26)]]
  length = 0

  for num in map(int, input().split()):
    curr = lst[num]
    if num + 1 > length:
      lst.append([])
      length += 1
    res += curr[0]
    lst[num + 1].append(curr[0])
    del curr[0]

  print(res)

'''
Thought Process:
1. Create a dict of all 26 lowercase letters, keeping track of their count of appearance in the string
2. Loop through the input (num)
3. Loop through the dictionary (item)
4. If the count of {item} == {num}, add it to the string, increment count by 1, go to the next num

-- Problem: Time limit exceeded?? (false alarm; it's just that PyPy ran my code slower :c first solution may probably work as well)
1. Create a list containing sublists (may be absurd to think about max 200k sublists) (lst)
2. At the initial state, first sublist contains all 26 lowercase letters
3. Loop through the input (num)
4. Add the first element of {lst[num]} into the string and move it to the next

Results:
ACCEPTED
Time - 312 ms
Memory - 32 000 KB
'''