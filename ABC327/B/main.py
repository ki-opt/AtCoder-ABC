B = int(input())

flag = False
for A in range(1,20,1):
	if pow(A,A) == B:
		print(A)
		flag = True
		break
if flag == False:
	print(-1)