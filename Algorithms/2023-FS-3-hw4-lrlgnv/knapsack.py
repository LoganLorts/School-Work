#Logan Lorts
# 12/9/2023

def knapSack(weight, wt, val, length): 
  
    # Base Case 
    if length == 0 or weight == 0: 
        return 0
    if (storage[length][weight] != 0): 
        return storage[length][weight]


    if (wt[length-1] > weight):
        storage[length][weight] = knapSack(weight, wt, val, length-1)
        return storage[length][weight]
    
    else: 
        storage[length][weight] = max( 
            val[length-1] + knapSack( 
                weight-wt[length-1], wt, val, length-1), 
            knapSack(weight, wt, val, length-1))
        return storage[length][weight]
  
#main 
length = int(input())
#weights = [0] * length
#values = [0] * length
weights = input().split()
values = input().split()
#print(weights)
#print(values)
for i in range(length):
    weights[i] = int(weights[i])
#print(weights)
for j in range(length):
    values[j] = int(values[j])
#print(values)
weight = int(input())
storage = [[0 for x in range(weight+1)] for y in range(length + 1)]
(knapSack(weight, weights, values, length))
#print(storage)
column = ([row[-1] for row in storage])
for i in range(len(column)):
    print(column[i])