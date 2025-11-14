bsize=int(input("Enter number of blocks:"))
blocks=[]
print("Enter sizes:")
for i in range(bsize):
    size=int(input("Enter size for block"+str(i+1)+":"))
    blocks.append(size)


psize=int(input("Enter number of processes:"))
process=[]
print("Enter sizes:")
for i in range(psize):
    size=int(input("Enter size for process"+str(i+1)+":"))
    process.append(size)

allocation=[]
for i in range(psize):
    allocation.append(-1)

def first_fit():
    for i in range(psize):
        for j in range(bsize):
            if blocks[j]>=process[i]:
                allocation[i]=j
                blocks[j]-=process[i]
                break
    

def next_fit():
    last_allocated_index=0
    for i in range(psize):
        count=0
        while count<bsize:
            j=(last_allocated_index+count)%bsize
            if blocks[j]>=process[i]:
                allocation[i]=j
                blocks[j]-=process[i]
                last_allocated_index=j
                break
            count+=1


def best_fit():
    best_index=-1
    for i in range(psize):
        for j in range(bsize):
            if blocks[j]>=process[i]:
                if best_index==-1 or blocks[j]<blocks[best_index]:
                    best_index=j
        
    if best_index!=-1:
        allocation[i]=best_index
        blocks[best_index]-=process[i]

def worst_fit():
    worst_index=-1
    for i in range(psize):
        for j in range(bsize):
            if blocks[j]>=process[i]:
                if worst_index==-1 or blocks[j]>blocks[worst_index]:
                    worst_index=j
        
    if worst_index!=-1:
        allocation[i]=worst_index
        blocks[worst_index]-=process[i]

def display():
        for i in range(psize):
            print("Process ",(i+1))
            if allocation[i]!=-1:
                print("allocated to block: ",allocation[i]+1)
            else:
                print("Not allocated")

while True:
    ch=int(input("Enter choice:"))