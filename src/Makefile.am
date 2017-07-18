jalaliincludedir = $(includedir)/jalali
jalaliinclude_HEADERS = ../include/jalali.h

noinst_PROGRAMS= jalali
jalali_SOURCES= jalali.c
jalali_CFLAGS = $(AM_CFLAGS)


lib_LTLIBRARIES= libjalali.la
libjalali_la_SOURCES= jalali.c
libjalali_la_LDFLAGS= -version-info $(LIBJALALI_SO_VERSION)
libjalali_la_LIBADD= $(LIBXMLXX_LIBS) \
		$(SQLITE3_LIBS) \
		-lssl \
		-lcrypto

