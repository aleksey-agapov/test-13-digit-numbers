/*
 * ThirteenTetradClass.cpp
 *
 *  Created on: Dec 7, 2021
 *      Author: user
 */

#include "ThirteenTetradClass.h"




namespace numbers {

	void ThirteenTetradClass::setNum(unsigned char num){
		if (num > ThirteenTetradClass::MAX_VAL) {
			store = ThirteenTetradClass::MAX_VAL;
			while (num-- > ThirteenTetradClass::MAX_VAL) {
				prtThirteenTetrad refHighObj = hight.lock();
				if (refHighObj) {
					refHighObj->increment();
				}
			}
		} else {
			store = num;
		}
	}

	unsigned char ThirteenTetradClass::getNum(){
		return store;
	}

	char ThirteenTetradClass::get(){
		return ThirteenTetradClass::TRANSLATE_TABLE[store];
	}

	void ThirteenTetradClass::setHight(nextThirteenTetrad hightObj) {
		this->hight = hightObj;
	}

	void ThirteenTetradClass::setLow(nextThirteenTetrad lowObj) {
		this->low = lowObj;
	}

	bool ThirteenTetradClass::increment() {
		if (store < ThirteenTetradClass::MAX_VAL) {
			store++;
		} else {
			prtThirteenTetrad refHighObj = hight.lock();
			if (refHighObj) {
				refHighObj->increment();
				store = ThirteenTetradClass::MIN_VAL;
			} else {
				return false;
			}
		}
		return true;
	}

	bool ThirteenTetradClass::stepLeft(int steps) {
		if (--steps <= 0) return false;
			prtThirteenTetrad refHighObj = hight.lock();
			if (refHighObj) {
				if (store > ThirteenTetradClass::MIN_VAL) {
					if (refHighObj->getNum() < ThirteenTetradClass::MAX_VAL) {
						if (refHighObj->increment()) {
							store--;
							return true;
						}
					} else {
						return refHighObj->stepLeft(steps);
					}
				} else {
					return refHighObj->stepLeft(steps);
				}
			}
			return false;
	}

	ThirteenTetradClass::~ThirteenTetradClass() {
		// TODO Auto-generated destructor stub
		store = 0;
	}
}
