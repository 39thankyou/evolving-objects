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
    Caner Candan <caner.candan@thalesgroup.com>
*/

#ifndef _edo_BounderRng_h
#define _edo_BounderRng_h

#include "Bounder.h"

namespace edo
{
    template < typename EOT >
    class BounderRng : public Bounder< EOT >
    {
    public:
	BounderRng( EOT min, EOT max, eo::RndGenerator< double > & rng )
	    : Bounder< EOT >( min, max ), _rng(rng)
	{}

	void operator()( EOT& x )
	{
	    unsigned int size = x.size();
	    assert(size > 0);

	    for (unsigned int d = 0; d < size; ++d) // browse all dimensions
		{

		    // FIXME: attention: les bornes RNG ont les memes bornes quelque soit les dimensions idealement on voudrait avoir des bornes differentes pour chaque dimensions.

		    if (x[d] < this->min()[d] || x[d] > this->max()[d])
			{
			    x[d] = _rng();
			}
		}
	}

    private:
	eo::RndGenerator< double> & _rng;
    };
}

#endif // !_edo_BounderRng_h

