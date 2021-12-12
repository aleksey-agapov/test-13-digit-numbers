/*
 * ThirteenNumberClass.cpp
 *
 *  Created on: Dec 8, 2021
 *      Author: user
 */

#include <algorithm>
#include "ThirteenNumberClass.h"

namespace numbers {

ThirteenNumberClass::ThirteenNumberClass() {
	// TODO Auto-generated constructor stub
	for (int index = 0;index < NUMBER_SIZE;index++){
		NumberTetrads[index] = std::make_shared<ThirteenTetradClass>(0);
		if (index) {
			NumberTetrads[index]->setLow(NumberTetrads[index-1]);
			NumberTetrads[index-1]->setHight(NumberTetrads[index]);
		}
	}
}

prtThirteenTetrad ThirteenNumberClass::operator[] (const int index) const {
	if (index < NUMBER_SIZE && index >= 0) {
		return NumberTetrads[index];
	}
	return nullptr;
}


const char * ThirteenNumberClass::toString(){
	int index = 0;
	memset(out_string, 0, NUMBER_SIZE);
	auto print = [&](prtThirteenTetrad item) {
		out_string[index++] = item->get();
	};
	std::for_each(NumberTetrads.rbegin(), NumberTetrads.rend(), print);
	return out_string;
}


bool ThirteenNumberClass::stepLeft(int index, int steps) {
	return NumberTetrads[index]->stepLeft(steps);
}


void ThirteenNumberClass::initRange(long sum, int start_pos, int stop_pos) {
	if ((stop_pos > start_pos) && (start_pos >= 0) && (stop_pos < NUMBER_SIZE)) {
		int full_position      = static_cast<int>(sum/ThirteenTetradClass::MAX_VAL);
		int last_val           = static_cast<int>(sum%ThirteenTetradClass::MAX_VAL);
		int index_pos          = 0;
		for (int index = start_pos; index <= stop_pos; index++) {
			if ((full_position > 0 ) && (full_position > index_pos)) {
				NumberTetrads[index]->setNum(ThirteenTetradClass::MAX_VAL);
			} else if (full_position == index_pos) {
				NumberTetrads[index]->setNum(last_val);
			} else {
				NumberTetrads[index]->setNum(ThirteenTetradClass::MIN_VAL);
			}
			index_pos++;
		}
	}
}

} /* namespace numbers */
