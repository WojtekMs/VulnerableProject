# Vulnerable

<a href="https://scan.coverity.com/projects/wojtekms-vulnerableproject">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/24285/badge.svg"/>
</a>

----------------------------- 

This project contains source code with vulnerabilities. Each example contains information how to build & run vulnerable code, how to experience the weakness and how to fix it applying a patch. Additionally, Makefile in the global workspace contains targets that allow you to run scans of the source code using:
- clang tidy 12
- cppcheck 
- flawfinder

## Examples
- [CWE-22](CWE-22/)
- [CWE-89](CWE-89/)
- [CWE-125](CWE-125/)
- [CWE-416](CWE-416/)
- [CWE-476](CWE-476/)


