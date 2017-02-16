The implementation of interval trees is done with the help of BST

Input format:<br />
n - no.of nodes to be added<br />
x[1] y[1] - interval 1 <br />
x[2] y[2] - interval 2

  .    .<br />
  .	   .<br />
  .    .<br />
  .    .<br />
  .    .<br />
x[n] y[n] - interval n<br />
q - no.of queries to be done<br />
x[1] y[1] - interval 1 <br />
x[2] y[2] - interval 2 

  .    .<br />
  .	   .<br />
  .    .<br />
  .    .<br />
  .    .<br />
x[q] y[q] - interval q<br /> 
d - no.of intervals to be deleted<br />
x[1] y[1] - interval 1 <br />
x[2] y[2] - interval 2 

  .    .<br />
  .	   .<br />
  .    .<br />
  .    .<br />
  .    .<br />
x[d] y[d] - interval d<br />

In the query operation for searching overlapping interval,<br />
all the intervals which overlap with the given interval <br />
printed.

In delete operation,the interval is deleted and the new <br />
obtained after updation is printed.

This impementation can also be done using Red black trees or AVL trees  

Note:The delete operation is done only by checking with the low key<br />
which means that we shld give only one interval with a particular low key<br />
Changes can be made to the above code to overcome his drawback but for the<br />
implementation is just for a basic idea.

Thank you :)
