/* Copyright (C) 2018 Thomas Jespersen, TKJ Electronics. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 *
 * Contact information
 * ------------------------------------------
 * Thomas Jespersen, TKJ Electronics
 * Web      :  http://www.tkjelectronics.com
 * e-mail   :  thomasj@tkjelectronics.com
 * ------------------------------------------
 */
 
#ifndef MODULES_CONTROLLERS_SLIDINGMODE_H
#define MODULES_CONTROLLERS_SLIDINGMODE_H

#include <stddef.h>
#include <stdlib.h>

#include "Parameters.h"

class SlidingMode
{
	public:
		SlidingMode(Parameters& params);
		~SlidingMode();

			void Step(float X[12], float q_ref[4], float tau[3], float S[3]);
		void HeadingIndependentReferenceManual(const float q_ref[4], const float q[4], float q_ref_out[4]);
		void HeadingIndependentQdot(const float dq[4], const float q[4], float q_dot_out[4]);

	private:
		void Saturation(float * in, int size, float epsilon, float * out);
		void Sign(float * in, int size, float * out);

	private:
		Parameters& _params;
};
	
	
#endif