cmake_minimum_required(VERSION 3.15...3.31)

project(FlashDB LANGUAGES CXX)

add_executable(flashdb
    src/Main.cpp
    src/TcpListener.cpp
    src/TcpStream.cpp
    src/ast/Lexer.cpp
    src/ast/Ast.cpp
    src/ast/InsertNode.cpp
    src/ast/SelectNode.cpp)
