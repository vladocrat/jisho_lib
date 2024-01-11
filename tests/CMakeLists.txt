cmake_minimum_required(VERSION 3.8)

find_package(GTest QUIET)

if(GTest_FOUND)
    message("GTest found")
else()
    message("No GTest found downloading")
	
    set(INSTALL_GTEST OFF CACHE BOOL "Do not install gtest" FORCE)
    set(INSTALL_GMOCK OFF CACHE BOOL "Do not install gmock" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
    configure_file(CMakeLists-gtest.txt.in "${CMAKE_CURRENT_BINARY_DIR}/googletest/CMakeLists.txt")
	
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" -S "${CMAKE_CURRENT_BINARY_DIR}/googletest" -B "${CMAKE_CURRENT_BINARY_DIR}/googletest2" RESULT_VARIABLE download_status)
	
    if (NOT "${download_status}" STREQUAL "0")
        message(FATAL_ERROR "Preparing GTest download - failed")
    endif()

    execute_process(COMMAND "${CMAKE_COMMAND}" --build "${CMAKE_CURRENT_BINARY_DIR}/googletest2" RESULT_VARIABLE download_status2)

    if (NOT "${download_status2}" STREQUAL "0")
        message(FATAL_ERROR "GTest download - failed")
    endif()

    message("GTest downloaded succesfully")

    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)
endif()

FILE(GLOB_RECURSE SOURCES *.cpp)

set(PROJECT_TEST_NAME test-${PROJECT_NAME})

add_executable(${PROJECT_TEST_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_TEST_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_TEST_NAME} gtest gmock_main ${PROJECT_NAME})

add_test(NAME ${PROJECT_TEST_NAME}-runner COMMAND ${PROJECT_TEST_NAME})
