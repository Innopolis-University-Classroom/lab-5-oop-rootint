# g++ -std=c++20 -o out example_main.cpp landlord.cpp
# g++ -c example_main.cpp
# g++ -c landlord.cpp
# g++ example_main.o landlord.o -o mainFile
# # ./
# g++ example_main.cpp landlord.cpp -L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib
# g++ landlord.cpp
# g++ example_main.cpp
# ./a.out
# g++-11 example_main.cpp landlord.cpp
# g++-11 -c example_main.cpp
# g++-11 -c landlord.cpp
# g++ example_main.o landlord.o -o mainFile
g++ example_main.cpp landlord.cpp -std=c++20