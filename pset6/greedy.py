height = 0
while height <= 0 or height > 23:
    try:
        height = int(input("height: "))
    except ValueError:
        continue

n = 2

i = height
while i > 0:
    print(" "*(i-1), "#"*n)
    n+=1
    i-=1