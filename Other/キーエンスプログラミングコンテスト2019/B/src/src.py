import re

S = input()

res = re.fullmatch('.*keyence', S)
if res: print('YES'),exit()
res = re.fullmatch('k.*eyence', S)
if res: print('YES'),exit()
res = re.fullmatch('ke.*yence', S)
if res: print('YES'),exit()
res = re.fullmatch('key.*ence', S)
if res: print('YES'),exit()
res = re.fullmatch('keye.*nce', S)
if res: print('YES'),exit()
res = re.fullmatch('keyen.*ce', S)
if res: print('YES'),exit()
res = re.fullmatch('keyenc.*e', S)
if res: print('YES'),exit()
res = re.fullmatch('keyence.*', S)
if res: print('YES'),exit()
print('NO')