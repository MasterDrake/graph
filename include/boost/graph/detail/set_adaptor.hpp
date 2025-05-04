// (C) Copyright Jeremy Siek 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_SET_ADAPTOR_HPP
#define BOOST_SET_ADAPTOR_HPP

#include <EASTL/set.h>
#include <boost/unordered_set.hpp>

namespace boost
{

template < class K, class C, class A, class T >
bool set_contains(const eastl::set< K, C, A >& s, const T& x)
{
    return s.find(x) != s.end();
}

template < class K, class H, class C, class A, class T >
bool set_contains(const boost::unordered_set< K, H, C, A >& s, const T& x)
{
    return s.find(x) != s.end();
}

template < class K, class C, class A >
bool set_equal(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y)
{
    return x == y;
}

// Not the same as lexicographical_compare_3way applied to eastl::set.
// this is equivalent semantically to bitset::operator<()
template < class K, class C, class A >
int set_lex_order(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y)
{
    typename eastl::set< K, C, A >::iterator xi = x.begin(), yi = y.begin(),
                                           xend = x.end(), yend = y.end();
    for (; xi != xend && yi != yend; ++xi, ++yi)
    {
        if (*xi < *yi)
            return 1;
        else if (*yi < *xi)
            return -1;
    }
    if (xi == xend)
        return (yi == yend) ? 0 : -1;
    else
        return 1;
}

template < class K, class C, class A > void set_clear(eastl::set< K, C, A >& x)
{
    x.clear();
}

template < class K, class C, class A >
bool set_empty(const eastl::set< K, C, A >& x)
{
    return x.empty();
}

template < class K, class C, class A, class T >
void set_insert(eastl::set< K, C, A >& x, const T& a)
{
    x.insert(a);
}

template < class K, class C, class A, class T >
void set_remove(eastl::set< K, C, A >& x, const T& a)
{
    x.erase(a);
}

template < class K, class C, class A >
void set_intersect(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y,
    eastl::set< K, C, A >& z)
{
    z.clear();
    eastl::set_intersection(
        x.begin(), x.end(), y.begin(), y.end(), eastl::inserter(z));
}

template < class K, class C, class A >
void set_union(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y,
    eastl::set< K, C, A >& z)
{
    z.clear();
    eastl::set_union(x.begin(), x.end(), y.begin(), y.end(), eastl::inserter(z));
}

template < class K, class C, class A >
void set_difference(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y,
    eastl::set< K, C, A >& z)
{
    z.clear();
    eastl::set_difference(
        x.begin(), x.end(), y.begin(), y.end(), eastl::inserter(z, z.begin()));
}

template < class K, class C, class A >
bool set_subset(const eastl::set< K, C, A >& x, const eastl::set< K, C, A >& y)
{
    return eastl::includes(x.begin(), x.end(), y.begin(), y.end());
}

// Shit, can't implement this without knowing the size of the
// universe.
template < class K, class C, class A >
void set_compliment(const eastl::set< K, C, A >& /*x*/, eastl::set< K, C, A >& z)
{
    z.clear();
}

} // namespace boost

#endif // BOOST_SET_ADAPTOR_HPP
