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

#ifndef _edoNormalMultiCenter_h
#define _edoNormalMultiCenter_h

#include "edoModifierMass.h"
#include "edoNormalMulti.h"

#ifdef WITH_BOOST

//! edoNormalMultiCenter< EOT >

template < typename EOT >
class edoNormalMultiCenter : public edoModifierMass< edoNormalMulti< EOT > >
{
public:
    typedef typename EOT::AtomType AtomType;

    void operator() ( edoNormalMulti< EOT >& distrib, EOT& mass )
    {
        ublas::vector< AtomType > mean( distrib.size() );
        std::copy( mass.begin(), mass.end(), mean.begin() );
        distrib.mean() = mean;
    }
};

#else
#ifdef WITH_EIGEN

template < typename EOT >
class edoNormalMultiCenter : public edoModifierMass< edoNormalMulti< EOT > >
{
public:
    typedef typename EOT::AtomType AtomType;
    // typedef typename edoNormalMulti<AtomType>::Vector Vector;
    typedef Eigen::Matrix< AtomType, 1, Eigen::Dynamic, Eigen::RowMajor> Vector;

    void operator() ( edoNormalMulti< EOT >& distrib, EOT& mass )
    {
        assert( distrib.size() == mass.innerSize() );
        Vector mean( mass );
        distrib.mean() = mean;
    }
};

#endif // WITH_EIGEN
#endif // WITH_BOOST


#endif // !_edoNormalMultiCenter_h
