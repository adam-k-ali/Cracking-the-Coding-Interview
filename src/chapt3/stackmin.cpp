
#include "../lib/stack.h"

int main() {
    stack s = stack({1, 2, 3, 4, 5, 1, -3, 1});
    s.print(true);
    s.print();
    return 0;
}