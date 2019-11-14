# Rational
C++ class implementing rational numbers. 
Avaible operators: +, -, *, /, <<, >>, ==, !=, >, >=, <, <=. 
Exponentiation with integer exponents is also available. 
Object Rational is auto shortening after every operation.



## Example

```cpp
#include "Rational.h"

int main()
{
	Rational r1, r2, result;

	std::cin >> r1 >> r2;
	result = r1 + r2;
	std::cout << r1 << " + " << r2 << " = " << result << std::endl;

	return 0;
}
```

```
2|8 -5|13
1|4 + -5|13 = -7|52
```
