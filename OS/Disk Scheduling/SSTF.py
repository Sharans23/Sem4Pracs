def calculateDiff(queue, head, diff):
    for i in range(len(queue)):
        diff[i][0] = abs(queue[i] - head)

def findMin(diff):
    index = -1
    minimum = float('inf')
    for i in range(len(diff)):
        if not diff[i][1] and diff[i][0] < minimum:
            minimum = diff[i][0]
            index = i
    return index

def SSTF(request, head):
    if not request:
        return

    l = len(request)
    diff = [[0, False] for _ in range(l)]
    seek_count = 0
    seek_sequence = [head]

    for _ in range(l):
        calculateDiff(request, head, diff)
        index = findMin(diff)
        if index == -1:
            break   

        diff[index][1] = True
        seek_count += diff[index][0]
        head = request[index]
        seek_sequence.append(head)

    print("Total number of seek operations =", seek_count)
    print("Seek sequence:")
    print(*seek_sequence, sep=", ")

if __name__ == "__main__":
    request = [176, 79, 34, 60, 92, 11, 41, 114]
    SSTF(request, 50)