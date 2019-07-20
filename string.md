<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
  - [13. Roman to Integer (easy)](#13-roman-to-integer-easy)
    - [Solution](#solution)
  - [](#)
<!-- TOC END -->



## 13. Roman to Integer (easy)

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
### Solution

```java
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> book = new HashMap<>();
        book.put('I', 1);
        book.put('V', 5);
        book.put('X', 10);
        book.put('L', 50);
        book.put('C', 100);
        book.put('D', 500);
        book.put('M', 1000);

        int rst = 0;
        for (int i = 0; i < s.length() - 1; i ++ ) {
            if (book.get(s.charAt(i)) < book.get(s.charAt(i+1))) {
                rst -= book.get(s.charAt(i));
            } else {
                rst += book.get(s.charAt(i));
            }
        }
        return rst + book.get(s.charAt(s.length()-1));
    }
}
```

##
