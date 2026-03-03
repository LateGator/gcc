/* Definitions of target machine for GNU compiler.
   NEC VR Series Processors
   Copyright (C) 2002-2025 Free Software Foundation, Inc.
   Contributed by Red Hat, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#undef MULTILIB_DEFAULTS
#define MULTILIB_DEFAULTS \
	{ MULTILIB_ENDIAN_DEFAULT,		\
	  MULTILIB_ABI_DEFAULT }

#undef DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS \
	/* Infer the default float setting from -march.  */		\
	MIPS_ARCH_FLOAT_SPEC,						\
									\
	/* Make -mabi=u32 the default on SGI RSP.  */			\
	"%{!mabi=*:%{!march=rsp:%(asm_abi_default_spec)} %{march=rsp:-mabi=u32}}",	\
									\
	/* Make -mlong32 -msym32 default for all ABIs except n64. */	\
	"%{!mabi=64:%{!mabi=u64:%{!mlong*:-mlong32}}}",			\
	"%{!mabi=64:%{!mabi=u64:%{!mno-sym32:%{!msym32:-msym32}}}}",	\
	"%{mabi=u64:%{mlong64:%{!mno-sym32:%{!msym32:-mno-sym32}}}}",	\
									\
	/* Make soft floats default on SGI RSP.  */			\
	"%{march=rsp:-msoft-float %{!mgpopt:-mno-gpopt}}",		\
									\
	/* Remove -mgp32 if it is redundant.  */			\
	"%{mabi=32:%<mgp32}",						\
	"%{mabi=u32:%<mgp32}",						\
									\
	/* Configuration-independent MIPS rules.  */			\
	BASE_DRIVER_SELF_SPECS
