
// prost (probas and stats)

// nemo (network mobilizer)
// Copyright (C) 2012-2014 Damien Magoni

/*
    This file is part of nemo.

    nemo is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation, either version 3 of 
    the License, or (at your option) any later version.

    nemo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with nemo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cmath>
#include "mt19937.h"
#include "prost.h"

namespace prost
{
	// return the nearest int of d
	long round_to_l(double d)
	{
		double n = 0;
		if ( fabs(modf(d, &n)) <= 0.5 )
			return static_cast<long>(n);
		else if ( d > 0 )
			return static_cast<long>(n) + 1;
		else
			return static_cast<long>(n) - 1;
	}

	// proba must be expressed in per cent (e.g. 37.4 %)
	bool roll(double pc_probability)
	{
		if ( random_l(1, 1000000000) <= round_to_l(10000000 * pc_probability) ) // precision = 7 digits after the point
			return true;
		else
			return false;
	}

	long random_l(long inf, long sup)
	{
		// Classic ANSI C rand() LC-PRNG
		// put next instruction at the beginning of the program
		// srand((unsigned)time(0));
		// return round_to_int((sup - inf) * static_cast<double>(rand()) / RAND_MAX) + inf;

		// Mersenne Twister GFSR-PRNG
		// put next instruction at the beginning of the program
		// init_genrand((unsigned long)s);
		return round_to_l((sup - inf) * static_cast<double>(mt19937::genrand_int32()) / 0xFFFFFFFFUL) + inf;
	}
}
