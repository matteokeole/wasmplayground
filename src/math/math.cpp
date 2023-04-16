float matrix[16];
float scalar;

__attribute__((export_name("get_matrix")))
void get_matrix(float *array) {
	array[0] = matrix[0];
	array[1] = matrix[1];
	array[2] = matrix[2];
	array[3] = matrix[3];
	array[4] = matrix[4];
	array[5] = matrix[5];
	array[6] = matrix[6];
	array[7] = matrix[7];
	array[8] = matrix[8];
	array[9] = matrix[9];
	array[10] = matrix[10];
	array[11] = matrix[11];
	array[12] = matrix[12];
	array[13] = matrix[13];
	array[14] = matrix[14];
	array[15] = matrix[15];
}

__attribute__((export_name("set_matrix")))
void set_matrix(float *array) {
	matrix[0] = array[0];
	matrix[1] = array[1];
	matrix[2] = array[2];
	matrix[3] = array[3];
	matrix[4] = array[4];
	matrix[5] = array[5];
	matrix[6] = array[6];
	matrix[7] = array[7];
	matrix[8] = array[8];
	matrix[9] = array[9];
	matrix[10] = array[10];
	matrix[11] = array[11];
	matrix[12] = array[12];
	matrix[13] = array[13];
	matrix[14] = array[14];
	matrix[15] = array[15];
}

__attribute__((export_name("get_scalar")))
float get_scalar() {
	return scalar;
}

__attribute__((export_name("set_scalar")))
void set_scalar(float number) {
	scalar = number;
}

__attribute__((export_name("multiply_scalar")))
void multiply_scalar() {
	matrix[0] *= scalar;
	matrix[1] *= scalar;
	matrix[2] *= scalar;
	matrix[3] *= scalar;
	matrix[4] *= scalar;
	matrix[5] *= scalar;
	matrix[6] *= scalar;
	matrix[7] *= scalar;
	matrix[8] *= scalar;
	matrix[9] *= scalar;
	matrix[10] *= scalar;
	matrix[11] *= scalar;
	matrix[12] *= scalar;
	matrix[13] *= scalar;
	matrix[14] *= scalar;
	matrix[15] *= scalar;
}