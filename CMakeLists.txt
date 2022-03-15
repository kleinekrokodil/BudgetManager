cmake_minimum_required(VERSION 3.20)
project(BudgetManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(BudgetManager main.cpp budget_manager.cpp budget_manager.h date.h parser.cpp parser.h)
