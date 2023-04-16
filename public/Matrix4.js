/**
 * @abstract
 * @extends Float32Array
 */
export class Matrix extends Float32Array {
	/**
	 * @param {Number} dimension
	 * @param {Object} elements
	 */
	constructor(dimension, elements) {
		super(dimension).set(elements);
	}
}

/**
 * @abstract
 * @param {Number} n
 * @returns {Matrix}
 */
Matrix.prototype.multiplyScalar;

/** @extends Matrix */
export class Matrix4 extends Matrix {
	/** @param {...Number} elements */
	constructor() {
		super(16, arguments);
	}
}

/** @override */
Matrix4.prototype.multiplyScalar = function(n) {
	for (let i = 0; i < 1_000_000; i++) {
		this[0] *= n;
		this[1] *= n;
		this[2] *= n;
		this[3] *= n;
		this[4] *= n;
		this[5] *= n;
		this[6] *= n;
		this[7] *= n;
		this[8] *= n;
		this[9] *= n;
		this[10] *= n;
		this[11] *= n;
		this[12] *= n;
		this[13] *= n;
		this[14] *= n;
		this[15] *= n;
	}

	return this;
};