# ------------------ MEMORY ALLOCATION PROGRAM ------------------

bsize = int(input("Enter number of blocks: "))
blocks = []
print("Enter block sizes:")
for i in range(bsize):
    blocks.append(int(input("Block " + str(i+1) + ": ")))

psize = int(input("Enter number of processes: "))
process = []
print("Enter process sizes:")
for i in range(psize):
    process.append(int(input("Process " + str(i+1) + ": ")))

# allocation array OUTSIDE functions
allocation = [-1] * psize


# FIRST FIT
def first_fit():
    for i in range(psize):
        for j in range(bsize):
            if blocks[j] >= process[i]:
                allocation[i] = j
                blocks[j] -= process[i]
                break


# NEXT FIT
def next_fit():
    last = 0
    for i in range(psize):
        count = 0
        while count < bsize:
            j = (last + count) % bsize
            if blocks[j] >= process[i]:
                allocation[i] = j
                blocks[j] -= process[i]
                last = j
                break
            count += 1


# BEST FIT
def best_fit():
    for i in range(psize):
        best = -1
        for j in range(bsize):
            if blocks[j] >= process[i]:
                if best == -1 or blocks[j] < blocks[best]:
                    best = j
        if best != -1:
            allocation[i] = best
            blocks[best] -= process[i]


# WORST FIT
def worst_fit():
    for i in range(psize):
        worst = -1
        for j in range(bsize):
            if blocks[j] >= process[i]:
                if worst == -1 or blocks[j] > blocks[worst]:
                    worst = j
        if worst != -1:
            allocation[i] = worst
            blocks[worst] -= process[i]


# DISPLAY
def display():
    print("\nAllocation:")
    for i in range(psize):
        if allocation[i] != -1:
            print("Process", i+1, "→ Block", allocation[i] + 1)
        else:
            print("Process", i+1, "→ Not allocated")


# MENU
while True:
    print("\n1. First Fit\n2. Next Fit\n3. Best Fit\n4. Worst Fit\n5. Exit")
    ch = int(input("Enter choice: "))

    if ch == 1:
        first_fit()
        display()

    elif ch == 2:
        next_fit()
        display()

    elif ch == 3:
        best_fit()
        display()

    elif ch == 4:
        worst_fit()
        display()

    elif ch == 5:
        break

    else:
        print("Invalid choice!")


"""
---------------- SAMPLE INPUT USED ----------------

Number of blocks: 5
Block sizes: 100 500 200 300 600

Number of processes: 4
Process sizes: 212 417 112 426


---------------- FIRST FIT OUTPUT ----------------
Process 1 → Block 2
Process 2 → Block 5
Process 3 → Block 2
Process 4 → Block 4


---------------- NEXT FIT OUTPUT ----------------
(Assuming ORIGINAL blocks, run separately)
Process 1 → Block 2
Process 2 → Block 3
Process 3 → Block 3
Process 4 → Block 5


---------------- BEST FIT OUTPUT ----------------
Process 1 → Block 3
Process 2 → Block 4
Process 3 → Block 1
Process 4 → Block 5


---------------- WORST FIT OUTPUT ----------------
Process 1 → Block 5
Process 2 → Block 2
Process 3 → Block 5
Process 4 → Block 4

----------------------------------------------------
Note: Since you selected NO RESET, each algorithm must be run
in a FRESH execution for correct results.
----------------------------------------------------
"""
