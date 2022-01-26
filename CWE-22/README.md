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
./tstat start ../CMakeLists.txt
./tstat stop
```

Observe that the file CMakeLists.txt which is outside the default log folder specified in the config.hpp is modified.

## Apply patch
You can apply patch by:
```bash
git apply path_traversal_fix.diff
```

Now if you try to execute the above mentioned commands you should get error: `invalid path!`.
## Reference
Link to the original application: https://github.com/WojtekMs/Tstat
