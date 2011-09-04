/*
The Evolving Distribution Objects framework (EDO) is a template-based,
ANSI-C++ evolutionary computation library which helps you to write your
own estimation of distribution algorithms.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Copyright (C) 2010 Thales group
*/
/*
Authors:
    Johann Dréo <johann.dreo@thalesgroup.com>
*/

#ifndef _edo_BounderUniform_h
#define _edo_BounderUniform_h

#include "Bounder.h"

namespace edo
{
    template < typename EOT >
    class BounderUniform : public Bounder< EOT >
    {
    public:
	BounderUniform( EOT min, EOT max )
	    : Bounder< EOT >( min, max )
	{}

	void operator()( EOT& sol )
	{
	    unsigned int size = sol.size();
	    assert(size > 0);

	    for (unsigned int d = 0; d < size; ++d) {

		if ( sol[d] < this->min()[d] || sol[d] > this->max()[d]) {
		    // use EO's global "rng"
		    sol[d] = rng.uniform( this->min()[d], this->max()[d] );
		}
	    } // for d in size
	}
    };
}

#endif // !_edo_BounderUniform_h
