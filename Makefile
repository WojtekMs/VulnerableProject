check_125:
	cppcheck --enable=all -I CWE-125/networking-src/ CWE-125/networking-src/ CWE-125/networking-exe/

tidy_125:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=-clang-analyzer-*,clang-analyzer-security*,cert-* -p CWE-125/build/ CWE-125/networking-src/ CWE-125/networking-exe/

flawfinder_125:
	flawfinder CWE-125/networking-exe/ CWE-125/networking-src/

check_22:
	cppcheck --enable=all -I CWE-22/src/tstat/ -I CWE-22/submodules/networking/networking-src/ CWE-22/src/tstat/src

tidy_22:
	run-clang-tidy-12 -clang-tidy-bin clang-tidy-12 -header-filter=.* -checks=-clang-analyzer-*,clang-analyzer-security*,cert-* -p CWE-22/build/ CWE-22/src/tstat/src

flawfinder_22:
	flawfinder CWE-22/src/tstat/src
