Just a simple benchmark to try and evaluate the cost of "per-frame" allocations.

One can simply run
```
cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build
build/bench
```
