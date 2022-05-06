

def autori(name_letters):
    abbreviation = name_letters[0]
    for i in range(1,len(name_letters)-1):
        if name_letters[i] == '-':
            abbreviation += name_letters[i+1]
    return abbreviation


# Single name in input
# name = input()
# print(autori(name))


# multiple names in input IN ONE LINE
# names = list(map(str, input("Enter multiple names: ").split()))
# for single_name in names:
#     print(autori(single_name))

# multiple names in input, single name in one line
n = int(input()) # first we need the amount of names
names = [input() for i in range(n)]
for i in range(n):
    print(autori(names[i]))


