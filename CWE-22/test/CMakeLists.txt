add_subdirectory(gtest)


set(TSTAT_TEST_SRC ArgParser-ut.cpp StartCommand-ut.cpp utils-ut.cpp TimeCounter-ut.cpp)
add_executable(tstat_test ${TSTAT_TEST_SRC})

target_link_libraries(tstat_test gtest_main tstat-lib)
add_test(NAME tstat_test COMMAND tstat_test)

add_custom_target(run tstat_test)
