class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

n = int(input())
line = input().strip().split()

head = None
for i in range(n):
    value = int(line[i])
    new_node = Node(value)
    
    if head is None:
        head = new_node
        new_node.next = head
    else:
        temp = head
        while temp.next != head:
            temp = temp.next
        temp.next = new_node
        new_node.next = head

try:
    k = int(input())
    if head is not None:
        current = head
        prev = None
        
        while True:
            if current.data == k:
                if head.next == head:
                    head = None
                elif current == head:
                    tail = head
                    while tail.next != head:
                        tail = tail.next
                    tail.next = head.next
                    head = head.next
                else:
                    prev.next = current.next
                break
            prev = current
            current = current.next
            if current == head:
                break
except:
    pass

if head is not None:
    temp = head
    first = True
    while True:
        if not first:
            print(" ", end="")
        print(temp.data, end="")
        first = False
        temp = temp.next
        if temp == head:
            break
    print()
else:
    print()
