from random import shuffle
with open("output.txt", "w") as q:
    s = [i for i in range(1, 101)]
    shuffle(s)
    q.write(' '.join(str(i) for i in s))
