#!/bin/sh
if [ -f Makefile ]; then
	echo "Making make distclean..."
	make distclean
fi
echo "Removing autogenned files..."
rm -rf libtool README.md stamp-h1 src/.main.c.swp autom4te.cache NEWS INSTALL AUTHORS COPYING libltdl src/.libs m4 config.guess config.sub configure install-sh missing mkinstalldirs Makefile.in ltmain.sh stamp-h.in */Makefile.in ltconfig stamp-h config.h.in* aclocal.m4 compile depcomp
echo "Done."
