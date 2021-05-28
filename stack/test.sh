#/bin/bash
clang++ -Wall -Wextra -Werror ftStack.cpp -o ftStack.out
clang++ -Wall -Wextra -Werror stdStack.cpp -o stdStack.out
./ftStack.out > ftStack.txt
./stdStack.out > stdStack.txt
diff ftStack.txt stdStack.txt
rm -rf ftStack.out stdStack.out ftStack.txt stdStack.txt