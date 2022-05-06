import sys

# AC

inputs = [input() for i in range(2)]
n = inputs[0]
n = int(n)
arild = list(inputs[1].split())
if len(arild) != n:
    print("something is fishy")
    sys.exit()

# changing all strings that are integers to int in arild
# and changing "mumble" to -1
for i in range(n):
    try:
        arild[i] = int(arild[i])
    except:
        arild[i] = -1

trueCount = 1
for number in arild:
    if number != trueCount and number != -1:
        print("something is fishy")
        sys.exit()
    if number == -1:
        trueCount += 1
        number = trueCount
    else:
        trueCount += 1
print("makes sense")


