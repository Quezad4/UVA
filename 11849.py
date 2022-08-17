import sys

def main():
    while True:
        f = set()
        count = 0
        n,a = list(map(int, sys.stdin.readline().split()))
        if(n == 0 and a == 0):
            break
        for i in range(n):
            x = int(sys.stdin.readline())
            f.add(x)
        for i in range(a):
            x = int(sys.stdin.readline())
            if x in f:
                count += 1
        sys.stdout.writelines(str(count)+"\n")
if __name__ == "__main__":
    main()
