const importObject = {
	imports: {
		imported_func: arg => console.log(arg),
	},
};

const response = await fetch("test.wasm");
const buffer = await response.arrayBuffer();
const object = await WebAssembly.instantiate(buffer, importObject);

object.instance.exports.exported_func();