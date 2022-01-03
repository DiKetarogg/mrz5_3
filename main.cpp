//////////////////////////////////////////////
// Лабораторная работа №3 по дисциплине МРЗвИС
// Выполнена студентом группы 921702 БГУИР Лабутин Андрей Александрович
// Данный файл является входом программы.
// 3.1.2022 v 0.1
//
// Используемые источники:
//  Методические материалы, wikipeda.org, одногруппники
///
#include <iostream>
#include <array>

#include <cstring>
#include <cmath>

#include "Teaching.hpp"

template<class Arg>
bool print(Arg arg) {
	if (cout.good()) {
		cout << arg;
	}
	else return 0;
	return cout.good();
}

template<class Arg1, class... Args>
bool print(Arg1 arg1, Args... args) {
	if (cout.good()) {
		cout << arg1;
		return print(args...);
	}
	else return 0;
	cout << flush;
	return cout.good();
}

template<class... Args>
bool println(Args... args) {
	if (print(args...)) {
		cout << '\n';
	} else return 0;
	return cout.good();
}

int main() {
	array<array<int, 9>, 3> sourceImages = {
		(array<int, 9>)
		{ 1, 1,1,
		  1,-1,1,
		  1,-1,1},
	
		(array<int, 9>)
		{1,1,1,
		1,-1,-1,
		1,-1,-1},

		(array<int, 9>)
		{1,-1,-1,
		1,-1,-1,
		1,1,1}
	};
	constexpr size_t sizeW = sourceImages.data()->size();

	array<array<double, sizeW>, sizeW>  wMatrix;
	array<int, sizeW> distortedImage = {1, -1, -1, 1, 1, -1, 1, 1, 1};
	/*
	 * # #
	 * * #
	 * * *
	 */
	array<double, sizeW> intermediateImage = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	array<int, sizeW> reconstructedImage;
	double coefficient = (double) round(((double)1 / wMatrix.size()) * 100) / 100;

	matrixInitialization(wMatrix);
	fillMatrix(wMatrix, sourceImages);
	remakeMatrix(wMatrix, coefficient);
	fillDiagonalWithZeros(wMatrix);
	createIntermediateImage(wMatrix, intermediateImage, distortedImage);
	restoreImage(intermediateImage, reconstructedImage);

	bool match = false;
	for (int i = 0; i < sourceImages.size(); i++){
		if (sourceImages[i] == reconstructedImage){
			println("Введённое изображение схоже с исходным изображением №", (i+1));
			match = true;
		}
	}
	if (!match) {
		print("Введённое изображение не имеет сходств не с одним из исходных изображений");
	}
}
