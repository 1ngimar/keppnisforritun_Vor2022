# AC

inputs = [input() for i in range(2)]
a = inputs[0]
b = inputs[1]
a = int(a)
b = int(b)

if a < 0:
    if b < 0:
        print(3)
    else:
        print(2)
else:
    if b < 0:
        print(4)
    else:
        print(1)