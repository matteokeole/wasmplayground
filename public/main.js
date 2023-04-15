const response = await fetch("public/build/todo.wasm");
const buffer = await response.arrayBuffer();
const object = await WebAssembly.instantiate(buffer);

await object.instance.exports._initialize();

console.log(object.instance.exports);
console.log(object.instance.exports.deg_to_rad(90));