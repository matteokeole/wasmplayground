Emscripten (C):
```bash
emcc -O3 src/<file>.c -o public/build/<file>.wasm --no-entry
```

Emscripten (C++):
```bash
em++ -O3 src/<file>.cpp -o public/build/<file>.wasm --no-entry
```