# flamAndroidAssignment_RijulBhatia

LRUCache:
  Data Strcutures used:
    - Doubly Linked List maintains the order of usage with dummy head and tail nodes.
    - Hash Map: provides O(1) access to nodes by key.
  Design:
    -Node struct: each node contains the key value pair and pointers to prev and next pointers.
    -Dummy Nodes: Head and tail dummy nodes to simplify edge case handling for removing, adding nodes.
    -Most receantly used items are near the head
    -Least receantly used items are near the tail
    -when an item is accessed, it is moved to the head.
  Time complexity:
    -get(key): O(1) hash map lookup + constant time list operations.
    -put(key, value): O(1).
  Space complexity: O(capacity) for stpring cache entries and linked list nodes.
  Working methodology:
    -get(key): look up the key in the hash map, if found , move the node to the head and return the value.
    -put(key, value):
      -if key exists, update value and move to head.
      -if key doesnt exist: create a new node, add to head and add to hash map.
      if capacity exceeded: remove the least receantly used node(before tail) and its hash map entry.


Custom HashMap:
  Data Structures used:
    -Array of linkedlists
  Design:
    -Uses an array of linked lists to handle hash collisions.
    -bucket size of 1000 is used.
    -Simple modulo operation for mapping keys to bucket indices.
    Node Struct: Each bucket contains a linked list of nodes storing kye value pairs.
  Time complexity:
    -Average case: O(1) for all operations i.e., put, get and remove.
    -Worst Case: O(n) if all keyys hash to the same bucket.
  Space complexity:
    -O(n), n is the number of key value pairs.
  Working methodology:
    -put(): Finds the bucket, checks if key exists, updates or inserts new node.
    -get(): Hashes the key, searches the bucket's linked list, returns value or -1.
    -remove(): Finds and removes the node from the appropriate bucket's linked list.
    
    
