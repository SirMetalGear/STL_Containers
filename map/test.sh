#/bin/bash
clang++ -Wall -Wextra -Werror ftMap.cpp -o ftMap.out
clang++ -Wall -Wextra -Werror stdMap.cpp -o stdMap.out
./ftMap.out > ftMap.txt
./stdMap.out > stdMap.txt
diff ftMap.txt stdMap.txt
rm -rf ftMap.out stdMap.out ftMap.txt stdMap.txt