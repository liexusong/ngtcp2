# ngtcp2

# Copyright (c) 2016 ngtcp2

# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:

# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
SUBDIRS = includes

AM_CFLAGS = $(WARNCFLAGS) $(EXTRACFLAG)
AM_CPPFLAGS = -I$(srcdir)/includes -I$(builddir)/includes -DBUILDING_NGTCP2

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libngtcp2.pc
DISTCLEANFILES = $(pkgconfig_DATA)

lib_LTLIBRARIES = libngtcp2.la

OBJECTS = \
	ngtcp2_pkt.c \
	ngtcp2_conv.c \
	ngtcp2_str.c \
	ngtcp2_buf.c \
	ngtcp2_upe.c \
	ngtcp2_conn.c \
	ngtcp2_mem.c \
	ngtcp2_pq.c \
	ngtcp2_rob.c

HFILES = \
	ngtcp2_pkt.h \
	ngtcp2_conv.h \
	ngtcp2_str.h \
	ngtcp2_buf.h \
	ngtcp2_upe.h \
	ngtcp2_conn.h \
	ngtcp2_mem.h \
	ngtcp2_pq.h \
	ngtcp2_rob.h \
	ngtcp2_macro.h

libngtcp2_la_SOURCES = $(HFILES) $(OBJECTS)
libngtcp2_la_LDFLAGS = -no-undefined \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)
