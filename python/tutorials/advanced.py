# auto list

l = [i for i in range(5)] # [0,1,2,3,4]

## input items

num = [int(input("insert number ")) for i in range(5)] # [1,2,3,4,5] (example)

# reverse

s = "abcd"
print(s)    # abcd
s.reverse()
print(s)    # dcba

# reversed (iteration only)

s = "abcd"
for i in reversed(s):
    print(i)             # dcba

# split number into digit array

num = 1234

## auto list

num = [int(i) for i in str(num)] # [1,2,3,4]

## map

num = list(map(int,str(num))) # [1,2,3,4]

