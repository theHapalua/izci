cmake_minimum_required(VERSION 3.10)

add_executable(MAIN src/main.cpp src/window.h src/window.cpp)

find_Package( PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
target_include_directories(MAIN PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_directories(MAIN PUBLIC ${GTKMM_LIBRARY_DIRS})
target_link_libraries(MAIN PUBLIC ${GTKMM_LIBRARIES})
