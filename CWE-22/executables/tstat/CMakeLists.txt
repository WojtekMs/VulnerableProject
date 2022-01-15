add_executable(tstat_daemon daemon_main.cpp)
add_executable(tstat tstat_main.cpp)

target_link_libraries(tstat_daemon tstat-lib networking-lib)
target_link_libraries(tstat tstat-lib networking-lib)
