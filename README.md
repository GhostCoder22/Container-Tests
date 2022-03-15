# ContainerTests
Based on Ralph Varjabedian's CLinkedList class example, which can be found at https://www.codeguru.com/cplusplus/better-method-of-creating-deleting-linked-lists-nodes, I've built two C++ template class' for building linked lists in the pointer-to-pointer technique. These are incomplete.

The first of these, TList builds orginary linked lists while the other, TList2W builds doubly linked lists (2 Way). Both of these template class' share common functionality between them for ease of use. Additionally, both TList and TList2W has a rudimentary "Walk" method that allows the developer trasnvere the linked list without the need for direct access to the linked list nodes, which they're built upon.

Lasty is the tests themselves. Within a single Code::Blocks project is two tests, both of which are nearly identical in almost every way with the same exact strings added to and removed from the linked lists. Both of these tests, while one being "TList Tests" whereas the other being "TList2W Tests", serve to thoroughly test the minipulation of linked lists.

Be aware these template class' are incomplete at this time.
