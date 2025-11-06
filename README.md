This code provides a simple IPv4 prefix management structure. The data structure is based on a dynamic array (vector) containing custom Prefix objects.
Each prefix stores a 32-bit IPv4 address and an 8-bit mask length.
Operation "add" validates prefix, searches to ensure no duplicates exist and adds the prefix to vector. Time complexity is O(n).
Operation "del" validates prefix and removes it from the vector by swapping with the last element and popping the back. Time complexity is O(n).
Check Operation (check) computes the mask for each prefix performs bitwise AND to compare network parts of addresses.
Selects the longest matching prefix. Also complexity O(n).
