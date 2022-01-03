#pragma once
using namespace std;
int sign(double x){
	if (x >= 0) return 1;
	else return -1;
}

template<size_t SIZEW>
void matrixInitialization(array<array<double, SIZEW>, SIZEW> &wMatrix){
	for (int i = 0; i < SIZEW; i++) {
		for (int j = 0; j < SIZEW; j++) {
			wMatrix[i][j] = 0;
		}
	}
}

template<size_t SIZEW, size_t SIZE>
void fillMatrix(array<array<double, SIZEW>, SIZEW> &wMatrix,
const array<array<int, SIZEW>, SIZE> &sourceMatrix) {
	for (const auto &matrix : sourceMatrix) {
		int count1 = 0;
		for (int i = 0; i < SIZEW; i++) {
			for (int j = 0; j < SIZEW; j++) {
				wMatrix[i][j] += matrix[count1] * matrix[j];
			}
			count1++;
		}
	}
}

template<size_t SIZEW>
void remakeMatrix(array<array<double,SIZEW>, SIZEW> &wMatrix, double coefficient){
	for (int i = 0; i < SIZEW; i++){
		for (int j = 0; j < SIZEW; j++) {
			wMatrix[i][j] *= coefficient;
		}
	}
}

template<size_t SIZEW>
void fillDiagonalWithZeros(array<array<double, SIZEW>, SIZEW> &wMatrix){
	for (int i = 0; i < wMatrix.size(); i++){
		wMatrix[i][i] = 0;
	}
}

template<size_t SIZEW>
void createIntermediateImage(const array<array<double, SIZEW>, SIZEW> &wMatrix,
array<double, SIZEW> &intermediateImage, const array<int, SIZEW> &distortedImage) {
	for (int i = 0; i < SIZEW; i++){
		for (int j = 0; j < SIZEW; j++) {
			intermediateImage[i] += wMatrix[i][j] * distortedImage[j];
		}
	}
}

template<size_t SIZEW>
void restoreImage(const array<double, SIZEW> &intermediateImage, array<int, SIZEW> &reconstructedImage){
	for (int i = 0; i < SIZEW; i++){
		reconstructedImage[i] = sign(intermediateImage[i]);
	}
}
