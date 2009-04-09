// { dg-options "-std=gnu++0x" }

// 2008-06-11  Paolo Carlini  <paolo.carlini@oracle.com>

// Copyright (C) 2008, 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.


#include <unordered_set>
#include <testsuite_hooks.h>

// DR 691.
void test01()
{
  bool test __attribute__((unused)) = true;

  typedef std::unordered_multiset<int> ums_type;
  ums_type ums;
  ums.insert(1);
  VERIFY( ums.cbegin(0) == ums.begin(0) );
  VERIFY( ums.cend(0) == ums.end(0) );
  const ums_type::size_type bn = ums.bucket(1);
  VERIFY( ums.cbegin(bn) != ums.cend(bn) );
}

int main()
{
  test01();
  return 0;
}
