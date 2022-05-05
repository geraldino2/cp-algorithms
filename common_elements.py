# Time complexity: O(n log n), but faster than unordered_set O(n) approach
import random
# fisher-yates
def shuffle(arr):
	for i in range(len(arr)):
		j = random.randint(0,i)
		arr[i], arr[j] = arr[j], arr[i]
A = [1,2,3,4,7,11]
B = [2,3,4,5,6,9,11]
shuffle(A)
shuffle(B)
A = sorted(A)
B = sorted(B)
N = len(A)
M = len(B)
i = 0
j = 0
common = []
while(i<N and j<M):
	if(A[i] == B[j]):
		common.append(A[i])
		i += 1
		j += 1
	elif(A[i]<B[j]):
		i += 1
	else:
		j += 1
print(common)