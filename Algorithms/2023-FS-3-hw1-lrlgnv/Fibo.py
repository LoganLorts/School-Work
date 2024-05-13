
user_num = int(input())
recursive_count = dict()

def recursive_fibo(N):
    recursive_count[(N)] = recursive_count.get(N, 0) + 1
    if N <= 1:
        return N
    else:
        return(recursive_fibo(N-1) + recursive_fibo(N-2))

def matrix_fibo(S, N):
    count = 8 #start at 8 because first 2 matrices assumed 
    base = [[0,1], 
            [1,1]]
    if N < 2: #accounts for first 2 numbers, which are 1
        return 1
    for x in range(N-2): #-2 to account for first 2 numbers being assumed
        storage = [[0,0], 
                   [0,0]]
        for i in range(len(S)):
            for j in range(len(S)):
                for k in range(len(S)):
                    storage[i][j] += S[i][k]*base[k][j]
                    count += 1
        S = storage
        #print(S) #return fibo matrix
        #print(S[1][1]) #return fibo number
    return(count)


print(recursive_fibo(user_num))
for key, count in reversed(recursive_count.items()):
    print('fibo(', key, ') : ', count)
base_matrix = [[0,1], 
               [1,1]]
print(matrix_fibo(base_matrix, user_num))
