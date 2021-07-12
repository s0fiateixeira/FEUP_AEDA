cmake_minimum_required(VERSION 3.10)
project(aeda2021_cp02)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda2021_cp02 main.cpp Tests/tests.cpp Tests/bst.h Tests/Restaurant.cpp Tests/Restaurant.h Tests/MealCourier.cpp Tests/MealCourier.h Tests/Client.cpp Tests/Client.h Tests/Order.cpp Tests/Order.h Tests/Courier.cpp Tests/Courier.h)

target_link_libraries(aeda2021_cp02 gtest gtest_main)
