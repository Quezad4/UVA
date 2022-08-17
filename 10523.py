import math
while True:
    try:
        ans = 0
        n,a = list(map(int,input().split()))
        for i in range(1,n+1):
            ans += i*pow(a,i)
        print(ans)
    except EOFError:
        break

    
