def firstFit(blockSize,blocks,processSize,processes): 
    count=0
    allocation = [-1] * n 
    for i in range(processes): 
        for j in range(blocks): 
            # check if blocksize greater than process size
            if blockSize[j] >= processSize[i]: 
                blockSize[j]=0
                allocation[i] = j 
                count=count+processSize[i]
                break

    print(" Process No. Process Size     Block no.") 
    for i in range(processes): 
        print(" ", i + 1, "      ", processSize[i], 
                        "        ", end = " ") 
        if allocation[i] != -1: 
            print(allocation[i] + 1) 
        else: 
            print("Not Allocated") 
    return count


def bestFit(blockSize, m, processSize, n): 
    allocation = [-1] * n 
    count=0
    for i in range(n): 
        bestIdx = -1
        for j in range(m): 
            if blockSize[j] >= processSize[i]: 
                if bestIdx == -1: 
                    bestIdx = j 
                elif blockSize[bestIdx] > blockSize[j]: 
                    bestIdx = j 
        if bestIdx != -1: 
            allocation[i] = bestIdx 
            blockSize[bestIdx] = 0
            count = count+processSize[i]

    print("Process No. Process Size  Block no.") 
    for i in range(n): 
        print(i + 1, "       ", processSize[i], 
                                end = "      ") 
        if allocation[i] != -1: 
            print(allocation[i] + 1) 
        else: 
            print("Not Allocated") 
    return count
    

def worstFit(blockSize, m, processSize, n): 
    allocation = [-1] * n 
    count = 0
    for i in range(n): 
        wstIdx = -1
        for j in range(m): 
            if blockSize[j] >= processSize[i]: 
                if wstIdx == -1: 
                    wstIdx = j 
                elif blockSize[wstIdx] < blockSize[j]: 
                    wstIdx = j 
        if wstIdx != -1:
            allocation[i] = wstIdx 
            blockSize[wstIdx] = 0
            count = count+processSize[i]

    print("Process No. Process Size Block no.") 
    for i in range(n): 
        print(i + 1, "       ", 
            processSize[i], end = "  ") 
        if allocation[i] != -1: 
            print(allocation[i] + 1) 
        else: 
            print("Not Allocated") 
    return count

blockSize = [] 
count1=0.0
count2=0.0
count3=0.0
blockSize2=[]
blockSize3=[]
processSize2=[]
processSize3=[]
m=int(input("enter the number of blocks:"))
n=int(input("enter the number of processes:"))
for i in range (0,m):
    a=(int(input(f"enter the {i+1} element block size:")))
    blockSize.append(a)
    blockSize2.append(a)
    blockSize3.append(a)
    count1=count1+blockSize[i]
    count2=count2+blockSize2[i]
    count3=count3+blockSize3[i]
processSize = [] 
print("C151 Sharan Shetty 60004220224")
for i in range (0,n):
    b=(int(input(f"enter the {i+1} element process size:")))
    processSize.append(b)
    processSize2.append(b)
    processSize3.append(b)


result1=firstFit(blockSize, m, processSize, n) 
mu1=result1/count1
print("First Fit")
print(result1)
print("memory utilization:",mu1)

result2=bestFit(blockSize2, m, processSize2, n) 
mu2=result2/count2
print("Best Fit")
print(result2)
print("memory utilization:",mu2)

result3=worstFit(blockSize3, m, processSize3, n) 
mu3=result3/count3
print("Worst Fit")
print(result3)
print("memory utilization:",mu3)