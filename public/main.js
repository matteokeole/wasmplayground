import {Matrix4OP} from "./Matrix4OP.js";
import {Matrix4} from "./Matrix4.js";

/* const matrix = new Matrix4(
	0, 1, 2, 3,
	4, 5, 6, 7,
	1, 9, 2, 8,
	1, 1, 9, 3,
);

console.time("1");

// Matrix4OP: ~232ms
// Matrix4: ~192ms
// for (let i = 0; i < 1_000_000; i++) {
	matrix.multiplyScalar(3);
// }

console.timeEnd("1"); */

const response = await fetch("public/build/math.wasm");
const buffer = await response.arrayBuffer();
const object = await WebAssembly.instantiate(buffer);

await object.instance.exports._initialize();

console.log(object.instance.exports);

const exports = object.instance.exports;

const array = new Float32Array(object.instance.exports.memory.buffer, 0, 16);
array.set([
	0, 1, 2, 3,
	4, 5, 6, 7,
	1, 9, 2, 8,
	1, 1, 9, 3,
]);

exports.set_matrix(array);

exports.set_scalar(3);

// console.log(array);

console.time("1");

// mat4 scalar product (1 000 000 times)
// 
// 1. Matrix4 (function constructor, extends Array): ~232ms
// 2. Matrix4 (ES6 class, extends Float32Array): ~192ms
// 3. WASM/C++ (JS loop, with params): ~580ms
// 4. WASM/C++ (C++ loop): ~12ms
// 5. WASM/C++ (JS loop, with params previously bound): ~20ms
for (let i = 0; i < 1_000_000; i++) exports.multiply_scalar();

console.timeEnd("1");

const result = new Float32Array(exports.memory.buffer, 16, 16);
exports.get_matrix(result);
console.log(result);