import math
def C(x,y):
    return math.factorial(x)//math.factorial(y)//math.factorial(x-y)
while True:
    n=int(input())
    if n==0:break
    dp=[]
    dp.append(1)
    for i in range(1,n):
        dp.append(2**(i*(i+1)//2))
        for j in range(i):
            dp[i]-=dp[j]*C(i,j)*(2**((i-j)*(i-j-1)//2))
    print(dp[-1])
    
