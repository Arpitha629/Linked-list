class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

n = int(input())
line = input().strip().split()

head = None
tail = None
for i in range(n):
    value = int(line[i])
    new_node = Node(value)
    
    if head is None:
        head = new_node
        tail = new_node
    else:
        tail.next = new_node
        tail = new_node

try:
    k = int(input())
    if head is not None:
        current = head
        prev = None
        
        while current is not None:
            if current.data == k:
                if prev is None:
                    head = head.next
                else:
                    prev.next = current.next
                break
            prev = current
            current = current.next
except:
    pass

current = head
first = True
while current is not None:
    if not first:
        print(" ", end="")
    print(current.data, end="")
    first = False
    current = current.next
print()
