# CWE-22
This code is vulnerable to the [CWE-22 "Path Traversal"](http://cwe.mitre.org/data/definitions/22.html) weakness, you can experiment with it yourself.

## Run example
```bash
mkdir build
cd build
cmake ..
make -j
make install
./tstat_daemon
./tstat start ../hello_there
./tstat stop
```

## Reference
Link to the original application: https://github.com/WojtekMs/Tstat
