Given two inclusive integer ranges [x1:x2] and 
[y1:y2], where x1 ≤ x2 and y1 ≤ y2, 
What is the most efficient way to test whether there is any overlap of the two ranges?

A simple implementation is as follows:
```
bool testOverlap(int x1, int x2, int y1, int y2) {
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
```

What does it mean for the ranges to overlap? It means there exists some number C which is in both ranges, i.e.
`x1 <= C <= x2`
and
`y1 <= C <= y2`

Now, if we are allowed to assume that the ranges are well-formed (so that x1 <= x2 and y1 <= y2) then it is sufficient to test
`x1 <= y2 && y1 <= x2`