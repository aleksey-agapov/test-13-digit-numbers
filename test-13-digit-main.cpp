/*
 * test_job_main.cpp
 *
 *  Created on: Dec 9, 2021
 *      Author: user
 */


#define SHOW_HELP "--help"
#define CALC_FULL "--full"

#include <iostream>
#include <memory>
#include <cstdlib>

#include "numbers/ThirteenNumberClass.h"

using namespace numbers;

/** максимальная сумма получаемая при сложении 6-ти разрядов */
static constexpr const long MAX_NICE_NUMBER_SIZE = 12 * RANGE_NUMBER_SIZE;

/**
 * Вывод красивого номера
 */
void printNiceNumber(long& nice_number_count, long& sum, ThirteenNumberClass& thirteenNumberClass, bool& full_count) {
	if (full_count) {
		for (int index = 0; index < NUMBER_SIZE; index++) {
			thirteenNumberClass[6]->setNum(index);
			nice_number_count++;
			std::cout << "Nice number:" << nice_number_count << " Value: " << thirteenNumberClass.toString() << " Sum: " << sum  << std::endl;
		}
	} else {
		nice_number_count++;
		std::cout << "Nice number:" << nice_number_count << " Value: " << thirteenNumberClass.toString() << " Sum: " << sum  << std::endl;
	}
}

/**
 * Анализ входных параметров
 */
bool setInputParm(int argc, char *argv[], bool& full_count) {
	if (argc > 1) {
		for(int count = 1; count < argc; count++ ) {
			if (!strcmp(argv[count], SHOW_HELP)) {
				return false;
			} else if (!strcmp(argv[count], CALC_FULL)) {
				full_count = true;
			} else {
				return false;
			}
		}
	}
	return true;
}

/**
 * Вывод информации о программе
 */
void showManual(int argc, char *argv[]){
	std::cout << "Pogramm: " << argv[0] << " - calculate and show nice numbers." << std::endl \
			  << "\tOptions:"  << std::endl \
			  << "\t\t--full - calculate and show full nice digital sequence with 7-rank discharge;" << std::endl \
			  << "\t\t--help - show this help" << std::endl;
}


int main(int argc, char *argv[])
{
	bool full_count = false;    // учитывать 7-й разряд
	long nice_number_count = 0; // счётчик красивых чисел,
	long item_sum = 0;          // номер комбинации чисел для 6-ти разрядной части

	if (!setInputParm(argc, argv, full_count)) {
		showManual(argc, argv);
		return EXIT_SUCCESS;
	}

	std::unique_ptr<ThirteenNumberClass> thirteenNumberClass = std::make_unique<ThirteenNumberClass>();

	std::cout << "Max sum: " << MAX_NICE_NUMBER_SIZE << " Starting..." << std::endl;
	// перебор всех комбинацый с каждым значением суммы
	do {
		std::cout << "Current sum: " << item_sum << std::endl;
		thirteenNumberClass->initRange(item_sum, 7, 12);	 // иницыализацыя старшей части суммой
		thirteenNumberClass->initRange(item_sum);	         // иницыализацыя младшей части суммой

		do {
			printNiceNumber(nice_number_count, item_sum, *thirteenNumberClass, full_count);
			while (thirteenNumberClass->stepLeft(7)) {    // сдвиг старшей на одну единицу
				printNiceNumber(nice_number_count, item_sum, *thirteenNumberClass, full_count);
			}

			thirteenNumberClass->initRange(item_sum, 7, 12); // вернуть старшую часть к начальному значению
		} while (thirteenNumberClass->stepLeft());       // сдвиг младшей части на одну единицу

	} while (item_sum++ < MAX_NICE_NUMBER_SIZE);

	std::cout << std::endl << "Nice numbers: " << nice_number_count << std::endl;

	return EXIT_SUCCESS;
}
