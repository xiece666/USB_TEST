import math
n=int(input())
a=math.factorial(2*n)
b=math.factorial(n)
print(a//b//b//(n+1))