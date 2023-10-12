n = int(input())
S = [input() for _ in range(n)]

ans = []
'''
for i in range(len(S[0])):
	k = i + 1
	flag = True
	tmp = S[0][i]
	while(flag):
		for j in range(1,n):
			if tmp not in S[j]:
				flag = False
				break
		if flag:
			ans.append(tmp)
			if k >= len(S[0]):
				break
			tmp += S[0][k]
			k += 1
		else:
			break
input(ans)
'''