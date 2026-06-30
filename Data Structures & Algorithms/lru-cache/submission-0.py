class Node:
    def __init__(self, key=-1, val=-1):
        self.key, self.val = key, val
        self.prev, self.next = None, None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {} # {key: (key, val)}
        self.head, self.tail = Node(), Node()
        self.head.next, self.tail.prev = self.tail, self.head

    '''
    head <==> ... x <==> node <==> y <==> tail
    '''
    def __insert(self, node):
        node.prev = self.tail.prev
        self.tail.prev.next = node
        node.next = self.tail
        self.tail.prev = node
    
    def __delete(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def get(self, key: int) -> int:
        if key in self.cache:
            # mark the element as most recently used element
            self.__delete(self.cache[key])
            self.__insert(self.cache[key])
            # return the value
            return self.cache[key].val
        # key doesn't exist, return -1
        return -1
        

    def put(self, key: int, value: int) -> None:
        # 1. if key alreay exist
        if key in self.cache:
            # 1.1 update the value
            # 1.2 mark the element as most recently used element
            node = Node(key, value)
            self.__delete(self.cache[key])
            self.cache[key] = node
            self.__insert(self.cache[key])
            
        # 2 if key doesnt' exist
        else:
            # 2.1 insert the element
            node = Node(key, value)
            self.cache[key] = node
            self.__insert(self.cache[key])
            # 2.2 check if size of cache increases then remove the least recently used element
            if len(self.cache) > self.cap:
                lru = self.head.next
                print(lru.key, self.cache)
                del self.cache[lru.key]
                self.__delete(lru)
