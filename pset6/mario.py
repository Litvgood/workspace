change = -1
while(change < 0):
    try:
        change = float(input("enter the amount: "))
    except ValueError:
        continue
    
amount = 0
rest = (round(change*100))

while not(rest == 0): 
    if (rest >= 25):
        rest -= 25
        amount+=1
    elif (rest >= 10):
        rest -= 10
        amount+=1
    elif (rest >= 5):
        rest -= 5
        amount+=1
    elif (rest >= 1):
        rest -= 1
        amount+=1

print(amount);