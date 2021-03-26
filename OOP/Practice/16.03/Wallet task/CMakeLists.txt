cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardTests Card/CardTests.cpp Card/Card.cpp catch_amalgamated.cpp)
add_executable(VirtualWalletTests VirtualWallet/VirtualWalletTests.cpp Card/Card.cpp VirtualWallet/VirtualWallet.cpp catch_amalgamated.cpp)