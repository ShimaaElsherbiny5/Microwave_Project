/*
 * BIT_MATH.h
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) (REG |=(1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM) (REG &=(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM) (REG ^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM) ((REG >>BIT_NUM)&1)

#endif /* LIB_BIT_MATH_H_ */
