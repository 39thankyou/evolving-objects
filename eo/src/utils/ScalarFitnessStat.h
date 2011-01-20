// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

//-----------------------------------------------------------------------------
// ScalarFitnessStat.h
// (c) Marc Schoenauer, Maarten Keijzer and GeNeura Team, 2000, 2001
/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: todos@geneura.ugr.es, http://geneura.ugr.es
             Marc.Schoenauer@polytechnique.fr
             mkeijzer@dhi.dk
 */
//-----------------------------------------------------------------------------

#ifndef _ScalarFitnessStat_h
#define _ScalarFitnessStat_h

#include <utils/RealVectorBounds.h>
#include <utils/Stat.h>

namespace eo
{

    /**
       The fitnesses of a whole population, as a std::vector

       @ingroup Stats
    */
    template <class EOT, class FitT = typename EOT::Fitness>
    class ScalarFitnessStat : public SortedStat<EOT, std::vector<double> >
    {
    public:

	using SortedStat<EOT, std::vector<double> >::value;

	ScalarFitnessStat(std::string _description = "FitnessES",
			    RealVectorBounds & _bounds = DummyVectorNoBounds)
	    : SortedStat<EOT,  std::vector<double> >(std::vector<double>(0), _description),
	      range(*_bounds[0])
        {}

	virtual void operator()(const std::vector<const EOT*>& _popPters)
	{
	    value().resize(_popPters.size());
	    for (unsigned i=0; i<_popPters.size(); i++)
		{
		    value()[i] = _popPters[i]->fitness();
		    range.truncate(value()[i]);
		}
	}

    private :
	RealBounds & range;
    };

}

#endif
