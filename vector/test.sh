#/bin/bash
clang++ -Wall -Wextra -Werror ftVector.cpp -o ftVector.out
clang++ -Wall -Wextra -Werror stdVector.cpp -o stdVector.out
./ftVector.out > ftVector.txt
./stdVector.out > stdVector.txt
diff ftVector.txt stdVector.txt
rm -rf ftVector.out stdVector.out ftVector.txt stdVector.txt