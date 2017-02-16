The implementation of interval trees is done with the help of BST

Input format:
n - no.of nodes to be added
x[1] y[1] - interval 1 
x[2] y[2] - interval 2
  .    .
  .	   .
  .    .
  .    .
  .    .
x[n] y[n] - interval n
q - no.of queries to be done
x[1] y[1] - interval 1 
x[2] y[2] - interval 2
  .    .
  .	   .
  .    .
  .    .
  .    .
x[q] y[q] - interval q 
d - no.of intervals to be deleted
x[1] y[1] - interval 1 
x[2] y[2] - interval 2
  .    .
  .	   .
  .    .
  .    .
  .    .
x[d] y[d] - interval d

In the query operation for searching overlapping interval,
only one interval which is first available is printed .

The impementation can also be done using Red black trees or AVL trees  