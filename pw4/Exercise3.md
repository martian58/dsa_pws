
# Explanation of Programs

**Press Ctrl+Shift+V in VS Code to open markdown view**

## Prog1: Swapping Two Integers Using Pointers
```c
void swap(int *p, int *q);
int main(void){
    int a = 3, b = 7;
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}

void swap(int *p, int *q){
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}
```

### Explanation:
1. **Purpose**:
   - This program swaps the values of two integers using pointers.

2. **Code Explanation**:
   - In `main`, the variables `a` and `b` are declared with values 3 and 7.
   - The `printf` statement displays their initial values (`3 7`).
   - The `swap` function is called with the addresses of `a` and `b`.
   - Inside `swap`: 
     - A temporary variable `tmp` is used to store the value of `*p`.
     - The value of `*p` is set to `*q`, and then `*q` is set to `tmp`.
   - This swaps the values of `a` and `b`.
   - The second `printf` statement in `main` displays the swapped values (`7 3`).
---

## Prog2: Finding the Minimum of Two Integers
```c
int min(int a, int b);
int main(void) {
    int j, k, m;
    printf("Input two integers: ");
    scanf("%d%d", &j, &k);
    m = min(j, k);
    printf("\n Of the two values %d and %d, the minimum is %d.\n\n", j, k, m);
    return 0;
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
```

### Explanation:
1. **Purpose**:
   - This program finds the minimum of two integers.

2. **Code Explanation**:
   - The program prompts the user to input two integers (`j` and `k`).
   - The function `min` is called with `j` and `k` as arguments.
   - Inside `min`:
     - The `if` statement checks if `a` is less than `b`.
     - If true, `a` is returned, else `b` is returned.
   - The result (`m`) is printed.
---

## Prog3: Pointer Manipulation
```c
#include <stdio.h>
int main(){
    int *px;
    int x;
    px = &x;
    *px = 0;
    printf(" x = %d \n", x);
    printf(" *px = %d \n", *px);
    *px += 5;
    printf(" x = %d\n", x);
    printf(" *px = %d\n", *px);
    (*px)++;
    printf(" x = %d\n", x);
    printf(" *px = %d\n", *px);
    return 0;
}
```

### Explanation:
1. **Purpose**:
   - This program demonstrates pointer usage to manipulate an integer variable.

2. **Code Explanation**:
   - A pointer `px` is declared, and `x` is an integer.
   - `px` is assigned the address of `x` (`px = &x`).
   - The statement `*px = 0` sets the value of `x` to `0` via the pointer.
   - The program prints the values of `x` and `*px`, which are both `0` because they reference the same memory location.
   - The line `*px += 5` increments the value of `x` by `5`. Now `x` becomes `5`.
   - The value is printed again (`x = 5` and `*px = 5`).
   - `(*px)++` increments `x` by `1`. Now `x` becomes `6`.
   - The final values are printed (`x = 6` and `*px = 6`).

---

## 20 points pliss 🙏 🙏 👍
