# $Id$

#######################################################################
# Default compilation parameters. Normally don't edit these           #
#######################################################################

srcdir      ?= .

DEFINES     := -DHAVE_CONFIG_H
LDFLAGS     :=
INCLUDES    := -I. -I$(srcdir) -I$(srcdir)/engines
LIBS        :=
OBJS        :=
DEPDIR      := .deps

MODULES     :=
MODULE_DIRS :=

# Load the make rules generated by configure
-include config.mk

CXXFLAGS:= -Wall $(CXXFLAGS)
CXXFLAGS+= -Wno-long-long -Wno-multichar -Wno-unknown-pragmas
# Even more warnings...
CXXFLAGS+= -pedantic -Wpointer-arith -Wcast-qual -Wconversion
CXXFLAGS+= -Wshadow -Wimplicit -Wundef -Wnon-virtual-dtor
CXXFLAGS+= -Wno-reorder -Wwrite-strings

# Disable RTTI and exceptions, and enabled checking of pointers returned by "new"
CXXFLAGS+= -fno-rtti -fno-exceptions -fcheck-new

# There is a nice extra warning that flags variables that are potentially
# used before being initialized. Very handy to catch a certain kind of
# bugs. Unfortunately, it only works when optimizations are turned on,
# which is why we normally don't use it.
#CXXFLAGS+= -O -Wuninitialized

#######################################################################
# Misc stuff - you should never have to edit this                     #
#######################################################################

EXECUTABLE  := scummvm$(EXEEXT)

include $(srcdir)/Makefile.common

# check if configure has been run or has been changed since last run
config.mk: $(srcdir)/configure
ifdef CONFIG_MK_IS_PRESENT
	@echo "Running $(srcdir)/configure with the last specified parameters"
	@sleep 2s
	LDFLAGS="$(SAVED_LDFLAGS)" CXX="$(SAVED_CXX)" CXXFLAGS="$(SAVED_CXXFLAGS)" CPPFLAGS="$(SAVED_CPPFLAGS)" \
		$(srcdir)/configure $(SAVED_CONFIGFLAGS)
else
	$(error You need to run $(srcdir)/configure before you can run make. Check $(srcdir)/configure --help for a list of parameters)
endif

include $(srcdir)/ports.mk
