s=input().replace('^','**').replace('/', '//')
t=s
S=0
for i in s:
    if i =='(':
        S+=1
    elif i==')':
        if S>0:S-=1
        else: t='('+t
if S>0:
    for i in range(S):
        t=t+')'
print(eval(t))