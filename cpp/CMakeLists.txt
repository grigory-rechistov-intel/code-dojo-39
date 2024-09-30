cmake_minimum_required(VERSION 3.5.0)
project(sing-a-song VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
set(gtest_force_shared_crt on)
enable_testing()

add_executable(song Song.cpp lib.cpp)

add_subdirectory(googletest)

add_executable(test_song test_song.cpp lib.cpp)
add_test(test_song test_song)
target_link_libraries(test_song gtest gmock gmock_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
