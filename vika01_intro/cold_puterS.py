
inputs = [input() for i in range(2)]
n = inputs[0]
temps = list(map(int, inputs[1].split()))
n = int(n)
counter  = 0
for item in temps:
   if item < 0:
       counter += 1
print(counter)