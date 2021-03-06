// Copyright 2015 by Martin Moene
//
// gsl-lite is based on GSL: Guidelines Support Library,
// https://github.com/microsoft/gsl
//
// This code is licensed under the MIT License (MIT). 
//

#pragma once

#ifndef GSL_TEST_GSL_LITE_H_INCLUDED
#define GSL_TEST_GSL_LITE_H_INCLUDED

#include "gsl-lite.h"
#include "lest_cpp03.hpp"

using namespace gsl;

#define CASE( name ) lest_CASE( specification(), name )

extern lest::tests & specification();

namespace lest { 

#if gsl_BETWEEN( gsl_COMPILER_MSVC_VERSION, 10, 12 )

inline std::string to_string( nullptr_t const & ) 
{ 
    return "nullptr";
}
#endif 

} // namespace lest

namespace gsl {

// use oparator<< instead of to_string() overload;
// see  http://stackoverflow.com/a/10651752/437272
inline std::ostream & operator<<( std::ostream & os, gsl::byte b )
{
    return os << std::hex << "0x" << static_cast<int>(b); 
}

} // namespace gsl

#endif // GSL_TEST_GSL_LITE_H_INCLUDED

// end of file
