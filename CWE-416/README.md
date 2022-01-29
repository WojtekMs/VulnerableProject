# CWE-416
This code is vulnerable to the [CWE-416 "Use After Free"](http://cwe.mitre.org/data/definitions/416.html) weakness, you can experiment with it yourself.


## Run example
To run this application:
```bash
cd shm
mkdir build
cd build
cmake ..
make -j
./shm
```

When you try to run any of these commands:
- print store cargo
- sell cargo
- buy cargo
- travel

You are accessing memory that was already freed. The result of this action is 'undefined behaviour' hence, I cannot provide a single expected output, but it can be any of those:
- segmentation fault (in case accessed memory was reassigned to a different process)
- strange values (in case accessed memory was reassigned to another variable in the scope of the same process)
- the same values in many places (same as above)

## Apply patch
You can apply patch by:
```bash
git apply use_after_free_fix.diff
```

Now if you try to print store cargo, sell or buy cargo while staying on the same island, everything should work fine. However, this fix helps only for a single CWE-416 weakness located inside `Store` class but this program contains more of these weaknesses caused by `Time` class which implements the Observer design pattern. Once subscribers are destroyed (and their memory is freed) they are not unsubscribed and `Time::notify` also tries to access memory that was already freed. It has the same consequences as the example described above. To resolve this issue all `TimeEffectables` should `detach` themselves in the destructors.
## Reference
Link to the original application: https://github.com/Kasia9311/object-oriented-programming/tree/game_okular
