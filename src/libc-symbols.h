/* Support macros for making weak and strong aliases for symbols,
   and for using symbol sets and linker warnings with GNU ld.
   Copyright (C) 1995-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _LIBC_SYMBOLS_H
#define _LIBC_SYMBOLS_H	1

/* Define ALIASNAME as a strong alias for NAME.  */
# define strong_alias(name, aliasname) _strong_alias(name, aliasname)
# define _strong_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((alias (#name)));

/* This comes between the return type and function name in
   a function definition to make that definition weak.  */
# define weak_function __attribute__ ((weak))
# define weak_const_function __attribute__ ((weak, __const__))

/* Define ALIASNAME as a weak alias for NAME.
   If weak aliases are not available, this defines a strong alias.  */
# define weak_alias(name, aliasname) _weak_alias (name, aliasname)
# define _weak_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((weak, alias (#name)));

/* Same as WEAK_ALIAS, but mark symbol as hidden.  */
# define weak_hidden_alias(name, aliasname) \
  _weak_hidden_alias (name, aliasname)
# define _weak_hidden_alias(name, aliasname) \
  extern __typeof (name) aliasname \
    __attribute__ ((weak, alias (#name), __visibility__ ("hidden")));

/* Declare SYMBOL as weak undefined symbol (resolved to 0 if not defined).  */
# define weak_extern(symbol) _weak_extern (weak symbol)
# define _weak_extern(expr) _Pragma (#expr)

#endif /* libc-symbols.h */
