tidy_checks = bugprone-*,cert-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,misc-*
check_125:
	cppcheck --enable=all -I CWE-125/networking-src/ CWE-125/networking-src/ CWE-125/networking-exe/

tidy_125:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=$(tidy_checks) -p CWE-125/build/ CWE-125/networking-src/ CWE-125/networking-exe/

flawfinder_125:
	flawfinder CWE-125/networking-exe/ CWE-125/networking-src/

check_22:
	cppcheck --enable=all -I CWE-22/src/tstat/ -I CWE-22/submodules/networking/networking-src/ CWE-22/src/tstat/src

tidy_22:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=$(tidy_checks) -p CWE-22/build/ CWE-22/src/tstat/src

flawfinder_22:
	flawfinder CWE-22/src/tstat/src CWE-22/src/tstat/tstat/

check_416:
	cppcheck --enable=all CWE-416/shm/

tidy_416:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=$(tidy_checks) -p CWE-416/shm/build/ CWE-416/shm/

flawfinder_416:
	flawfinder CWE-416/shm/

check_476:
	cppcheck --enable=all -I CWE-476/include/ CWE-476/src/

tidy_476:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=$(tidy_checks) -p CWE-476/build/ CWE-476/src/

flawfinder_476:
	flawfinder CWE-476/include/ CWE-476/src/

check_89:
	cppcheck --enable=all CWE-89/

# this check needs to be run inside docker container with mysql++ code or it is required to install mysql++ locally
tidy_89:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=$(tidy_checks) -p CWE-89/build CWE-89/

flawfinder_89:
	flawfinder CWE-89/
