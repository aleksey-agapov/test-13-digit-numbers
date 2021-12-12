/*
 * ThirteenNumberClass.h
 *
 *  Created on: Dec 8, 2021
 *      Author: user
 */

#ifndef NUMBERS_THIRTEENNUMBERCLASS_H_
#define NUMBERS_THIRTEENNUMBERCLASS_H_

#define NUMBER_SIZE 13
#define RANGE_NUMBER_SIZE 6

#include <array>
#include "ThirteenTetradClass.h"

namespace numbers {


/**
 * Класс управления 13-разрядным числом в тринадцатиричной системе исчисления
 */
class ThirteenNumberClass {
private:
	std::array<prtThirteenTetrad, NUMBER_SIZE> NumberTetrads;
	char out_string[NUMBER_SIZE];
public:
	static constexpr const char BAD_CHAR_VALUE = 'X';
	static constexpr const unsigned char BAD_NUM_VALUE = 255;

	/** доступ к любому разряду */
	prtThirteenTetrad operator[] (const int index) const;

	/** число в строку */
	const char * toString();

	/** сдвиг суммы на один разряд */
	bool stepLeft(int index = 0, int steps = RANGE_NUMBER_SIZE);

	/** иницыализировать диапазон суммой 6-ти разрядов */
	void initRange(long sum, int start_pos = 0, int stop_pos = RANGE_NUMBER_SIZE - 1);

	ThirteenNumberClass();
	virtual ~ThirteenNumberClass() {}
};

} /* namespace numbers */

#endif /* NUMBERS_THIRTEENNUMBERCLASS_H_ */
