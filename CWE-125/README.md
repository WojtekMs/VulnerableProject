# CWE-125
This code is vulnerable to the [CWE-125 "Out-of-bounds Read"](http://cwe.mitre.org/data/definitions/125.html) weakness, you can experiment with it yourself.

## Run example
```bash
mkdir build
cd build
cmake ..
make -j
cd networking-exe
./server
```

Run another terminal instance.

```bash
cd <cwe-125-workspace>
cd build/networking-exe
./client
Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size! Long message which exceeds 256 characters which is the buffer size!
```

Observe that the server crashes with Segmentation Fault.

## Reference
Link to the original application: https://github.com/WojtekMs/Networking
