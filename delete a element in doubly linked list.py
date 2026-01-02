class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

n = int(input())
numbers = list(map(int, input().split()))

head = None

for num in numbers:
    new_node = Node(num)
    
    if head is None:
        head = new_node
    else:
        current = head
        while current.next:
            current = current.next
        current.next = new_node
        new_node.prev = current

try:
    k = int(input())
    current = head
    while current:
        if current.data == k:
            if current.prev is None:
                head = current.next
                if head:
                    head.prev = None
            elif current.next is None:
                current.prev.next = None
            else:
                current.prev.next = current.next
                current.next.prev = current.prev
            break
        current = current.next
except:
    pass

current = head
while current:
    print(current.data, end=" ")
    current = current.next
print()
