export function Matrix4OP(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) {
	this.push.call(this, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
}

Matrix4OP.prototype = Array.prototype;

Matrix4OP.prototype.multiplyScalar = function(n) {
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
};