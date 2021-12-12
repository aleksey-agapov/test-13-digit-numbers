/*
 * ThirteenTetradClass.h
 *
 *  Created on: Dec 7, 2021
 *      Author: user
 */

#ifndef NUMBERS_THIRTEENTETRADCLASS_H_
#define NUMBERS_THIRTEENTETRADCLASS_H_

#define NUMBER_IN_TRANSLATE_TABLE_NOT_FOUND 127
#define NUMBER_RANK 13

#include <memory>
#include <string.h>

namespace numbers {

class ThirteenNumberClass;
class ThirteenTetradClass;

using nextThirteenTetrad = std::weak_ptr<numbers::ThirteenTetradClass>;
using prtThirteenTetrad  = std::shared_ptr<numbers::ThirteenTetradClass>;

/**
 * Класс управления числом в тринадцатиричной системе исчисления
 */
class ThirteenTetradClass {
private:
	static constexpr const char * TRANSLATE_TABLE = "0123456789ABC";
	static constexpr size_t TRANSLATE_TABLE_SIZE = strlen(TRANSLATE_TABLE);
	static constexpr const unsigned char MAX_VAL = 12;
	static constexpr const unsigned char MIN_VAL = 0;
	unsigned char store;
	nextThirteenTetrad hight;
	nextThirteenTetrad low;

public:
	ThirteenTetradClass() : store(0) {}
	ThirteenTetradClass(unsigned char init) : store(init) {}

	/** установить значение числа */
	void setNum(unsigned char value);
	/** получить значение числа */
	unsigned char getNum();
	/** получить значение в виде символа */
	char get();
	/** установить ссылку на старший разряд */
	void setHight(nextThirteenTetrad hightObj);
	/** установить ссылку на младший разряд */
	void setLow(nextThirteenTetrad lowObj);
	/** увеличить значение на 1 */
	bool increment();
	/** сдвиг суммы на один разряд  */
	bool stepLeft(int steps);

	virtual ~ThirteenTetradClass();

	// Делаем класс ThirteenNumberClass другом класса ThirteenTetradClass
	friend class ThirteenNumberClass;
};

}
#endif /* NUMBERS_THIRTEENTETRADCLASS_H_ */
