def bubble(l1, n):
    if n == 0 or n == 1:
        return
    for i in range(n - 1):
        if l1[i] > l1[i + 1]:
            l1[i], l1[i + 1] = l1[i + 1], l1[i]

    bubble(l1, n - 1)


l1 = [3, 5, 7, 2, 1]
n = len(l1)
bubble(l1, n)
print(l1)
