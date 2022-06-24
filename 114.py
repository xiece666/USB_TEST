n=int(input())
a=[]
ans=0
t=input().split()
a0=int(t[0])
b0=int(t[1])
s=a0
for i in range(n):
    b=input().split()
    c=[]
    c.append(int(b[0]))
    c.append(int(b[1]))
    a.append(c)
a.sort(key=lambda x:x[0]*x[1])
for i in range(n):
    ans=max(ans,s//(a[i])[1])
    s*=(a[i])[0]
print(ans)
