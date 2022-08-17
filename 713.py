t =int(input())
for i in range(t):
    x,y = input().split()
    x = x[::-1]
    y = y[::-1]
    x =int(x)
    y =int(y)
    soma = str(x+y)
    soma = soma[::-1]
    print(soma.strip('0'))
    
