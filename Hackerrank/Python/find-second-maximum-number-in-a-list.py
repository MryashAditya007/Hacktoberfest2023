if __name__ == '__main__':
    n = int(input())
    arr1 = map(int, input().split())
    arr = sorted(list(arr1))
    a = 0
    for i in range(n):
        while arr[n-(i+1)] == max(arr):
            a = arr[n-(i+2)]
            break

print(a)