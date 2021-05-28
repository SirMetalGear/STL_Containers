#/bin/bash
clang++ -Wall -Wextra -Werror ftQueue.cpp -o ftQueue.out
clang++ -Wall -Wextra -Werror stdQueue.cpp -o stdQueue.out
./ftQueue.out > ftQueue.txt
./stdQueue.out > stdQueue.txt
diff ftQueue.txt stdQueue.txt
rm -rf ftQueue.out stdQueue.out ftQueue.txt stdQueue.txt