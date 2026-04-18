
#cmake сгенерировал


cmake_minimum_required(VERSION 3.14)
project(TableAndTreeLab)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


file(GLOB ALL_SOURCES 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
    CONFIGURE_DEPENDS 
    "*.cpp"
)
file(GLOB PROJECT_HEADERS 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
    CONFIGURE_DEPENDS 
    "*.h"
)

list(REMOVE_ITEM ALL_SOURCES "Sample.cpp" "test_polinom.cpp" "test_mas.cpp" "test_umas.cpp" "test_tree.cpp" "test_table.cpp")


add_library(CoreLogic STATIC ${ALL_SOURCES} ${PROJECT_HEADERS})
target_include_directories(CoreLogic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MainApp Sample.cpp)
target_link_libraries(MainApp PRIVATE CoreLogic)


add_executable(tables_test test_polinom.cpp test_mas.cpp test_umas.cpp test_tree.cpp test_table.cpp)
target_include_directories(tables_test PRIVATE ${googletest_SOURCE_DIR}/googletest/include)
target_include_directories(tables_test PRIVATE ${googletest_SOURCE_DIR}/googlemock/include)


target_link_libraries(tables_test PRIVATE CoreLogic gtest gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND tables_test)

add_custom_command(TARGET tables_test POST_BUILD
    COMMAND tables_test
    COMMENT "--- ЗАПУСК ТЕСТОВ ПОСЛЕ СБОРКИ ---"
)

set_target_properties(tables_test PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/test/Release"
)
