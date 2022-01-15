# CWE-22
This code is vulnerable to the [CWE-22 "Path Traversal"](http://cwe.mitre.org/data/definitions/22.html) weakness, you can experiment with it yourself.

## Run example
Edit the default path in the `src/tstat/tstat/config.hpp` file.  
Set the log_save_path to the current path for example.

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

Observe that the folder hello_there is created outside the default log folder specified in the config.hpp.
## Reference
Link to the original application: https://github.com/WojtekMs/Tstat
