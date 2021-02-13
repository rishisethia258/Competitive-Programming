# Policy based data structures 

The g++ compiler also supports some data structures that are not part of the C++ standard library. Such structures are called policy-based data structures. These data structures are designed for high-performance, flexibility, semantic safety, and conformance to the corresponding containers in std.

### Ordered Set

Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. It performs all the operations as performed by the set data structure in STL in log(n) complexity and performs two additional operations also in log(n) complexity.

- order_of_key(k) : Number of items strictly smaller than k .
- find_by_order(k) : K-th element in a set (counting from zero).

##### Difference between set and ordered set
There is not so much difference between the set and ordered set although ordered set can be assumed as an extended version of set capable of performing some more advanced functions(stated above) that are extensively used in competitive programming.

##### Code
```
#define RBT rb_tree_tag
#define TSNU tree_order_statistics_node_update
template <typename T>
using oset = tree<T,null_type,less<T>,RBT,TSNU>;
template <typename T>
using omultiset = tree<T,null_type,less_equal<T>,RBT,TSNU>; 

```
