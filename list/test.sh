#/bin/bash
clang++ -Wall -Wextra -Werror ftList.cpp -o ftList.out
clang++ -Wall -Wextra -Werror stdList.cpp -o stdList.out
./ftList.out > ftList.txt
./stdList.out > stdList.txt
diff ftList.txt stdList.txt
rm -rf ftList.out stdList.out ftList.txt stdList.txt