#############################################################################
# Makefile for building: libqwt_designer_plugin.so
# Generated by qmake (2.01a) (Qt 4.8.4) on: ?? 11? 24 11:06:21 2015
# Project:  designer.pro
# Template: lib
# Command: /usr/lib/i386-linux-gnu/qt4/bin/qmake -o Makefile designer.pro
#############################################################################

####### Compiler, tools and options

CC            = @echo compiling $< && gcc
CXX           = @echo compiling $< && g++
DEFINES       = -DQT_NO_DEBUG -DQT_NO_KEYWORDS -DQT_PLUGIN -DQT_SCRIPT_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQDESIGNER_EXPORT_WIDGETS -DQT_SHARED
CFLAGS        = -pipe -O2 -D_REENTRANT -Wall -W -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -D_REENTRANT -Wall -W -fPIC $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtScript -I/usr/include/qt4 -I../src -Imoc
LINK          = @echo linking $@ && g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/qwt-6.1.0/lib -shared
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -L/home/wuqiankun/文档/FunySpace/WorkSpace/libqwt-doc/SourceProject/qwt-6.1.0/designer/../lib -lqwt -lQtScript -lQtXml -lQtGui -lQtCore -lQtDesigner -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/i386-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = qwt_designer_plugin.cpp \
		qwt_designer_plotdialog.cpp moc/moc_qwt_designer_plugin.cpp \
		moc/moc_qwt_designer_plotdialog.cpp \
		resources/qrc_qwt_designer_plugin.cpp
OBJECTS       = obj/qwt_designer_plugin.o \
		obj/qwt_designer_plotdialog.o \
		obj/moc_qwt_designer_plugin.o \
		obj/moc_qwt_designer_plotdialog.o \
		obj/qrc_qwt_designer_plugin.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		../qwtconfig.pri \
		../qwtbuild.pri \
		../qwtfunctions.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/designer.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/silent.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		designer.pro
QMAKE_TARGET  = qwt_designer_plugin
DESTDIR       = plugins/designer/
TARGET        = libqwt_designer_plugin.so
TARGETD       = libqwt_designer_plugin.so

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile  plugins/designer/$(TARGET)

plugins/designer/$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@$(CHK_DIR_EXISTS) plugins/designer/ || $(MKDIR) plugins/designer/ 
	-$(DEL_FILE) $(TARGET)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-$(MOVE) $(TARGET) plugins/designer/



Makefile: designer.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		../qwtconfig.pri \
		../qwtbuild.pri \
		../qwtfunctions.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/designer.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/silent.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtScript.prl \
		/usr/lib/i386-linux-gnu/libQtXml.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl \
		/usr/lib/i386-linux-gnu/libQtDesigner.prl
	$(QMAKE) -o Makefile designer.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
../qwtconfig.pri:
../qwtbuild.pri:
../qwtfunctions.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/designer.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/silent.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtScript.prl:
/usr/lib/i386-linux-gnu/libQtXml.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
/usr/lib/i386-linux-gnu/libQtDesigner.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile designer.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/qwt_designer_plugin6.1.0 || $(MKDIR) obj/qwt_designer_plugin6.1.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/qwt_designer_plugin6.1.0/ && $(COPY_FILE) --parents qwt_designer_plugin.h qwt_designer_plotdialog.h obj/qwt_designer_plugin6.1.0/ && $(COPY_FILE) --parents qwt_designer_plugin.qrc obj/qwt_designer_plugin6.1.0/ && $(COPY_FILE) --parents qwt_designer_plugin.cpp qwt_designer_plotdialog.cpp obj/qwt_designer_plugin6.1.0/ && (cd `dirname obj/qwt_designer_plugin6.1.0` && $(TAR) qwt_designer_plugin6.1.0.tar qwt_designer_plugin6.1.0 && $(COMPRESS) qwt_designer_plugin6.1.0.tar) && $(MOVE) `dirname obj/qwt_designer_plugin6.1.0`/qwt_designer_plugin6.1.0.tar.gz . && $(DEL_FILE) -r obj/qwt_designer_plugin6.1.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_qwt_designer_plugin.cpp moc/moc_qwt_designer_plotdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_qwt_designer_plugin.cpp moc/moc_qwt_designer_plotdialog.cpp
moc/moc_qwt_designer_plugin.cpp: qwt_designer_plugin.h
	@echo moc qwt_designer_plugin.h && /usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) qwt_designer_plugin.h -o moc/moc_qwt_designer_plugin.cpp

moc/moc_qwt_designer_plotdialog.cpp: qwt_designer_plotdialog.h
	@echo moc qwt_designer_plotdialog.h && /usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) qwt_designer_plotdialog.h -o moc/moc_qwt_designer_plotdialog.cpp

compiler_rcc_make_all: resources/qrc_qwt_designer_plugin.cpp
compiler_rcc_clean:
	-$(DEL_FILE) resources/qrc_qwt_designer_plugin.cpp
resources/qrc_qwt_designer_plugin.cpp: qwt_designer_plugin.qrc \
		pixmaps/qwtslider.png \
		pixmaps/qwtdial.png \
		pixmaps/qwtwheel.png \
		pixmaps/qwtplot.png \
		pixmaps/qwtscale.png \
		pixmaps/qwtanalogclock.png \
		pixmaps/qwtcounter.png \
		pixmaps/qwtcompass.png \
		pixmaps/qwtknob.png \
		pixmaps/qwtthermo.png \
		pixmaps/qwtwidget.png
	@echo rcc qwt_designer_plugin.qrc && /usr/lib/i386-linux-gnu/qt4/bin/rcc -name qwt_designer_plugin qwt_designer_plugin.qrc -o resources/qrc_qwt_designer_plugin.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

obj/qwt_designer_plugin.o: qwt_designer_plugin.cpp qwt_designer_plugin.h \
		qwt_designer_plotdialog.h \
		../src/qwt_plot.h \
		../src/qwt_global.h \
		../src/qwt_text.h \
		../src/qwt_plot_dict.h \
		../src/qwt_plot_item.h \
		../src/qwt_legend_data.h \
		../src/qwt_graphic.h \
		../src/qwt_null_paintdevice.h \
		../src/qwt_scale_map.h \
		../src/qwt_transform.h \
		../src/qwt_interval.h \
		../src/qwt_plot_canvas.h \
		../src/qwt_scale_widget.h \
		../src/qwt_scale_draw.h \
		../src/qwt_abstract_scale_draw.h \
		../src/qwt_scale_div.h \
		../src/qwt_counter.h \
		../src/qwt_wheel.h \
		../src/qwt_thermo.h \
		../src/qwt_abstract_scale.h \
		../src/qwt_knob.h \
		../src/qwt_abstract_slider.h \
		../src/qwt_slider.h \
		../src/qwt_dial.h \
		../src/qwt_dial_needle.h \
		../src/qwt_analog_clock.h \
		../src/qwt_compass.h \
		../src/qwt_round_scale_draw.h \
		../src/qwt_text_label.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qwt_designer_plugin.o qwt_designer_plugin.cpp

obj/qwt_designer_plotdialog.o: qwt_designer_plotdialog.cpp qwt_designer_plotdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qwt_designer_plotdialog.o qwt_designer_plotdialog.cpp

obj/moc_qwt_designer_plugin.o: moc/moc_qwt_designer_plugin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_qwt_designer_plugin.o moc/moc_qwt_designer_plugin.cpp

obj/moc_qwt_designer_plotdialog.o: moc/moc_qwt_designer_plotdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_qwt_designer_plotdialog.o moc/moc_qwt_designer_plotdialog.cpp

obj/qrc_qwt_designer_plugin.o: resources/qrc_qwt_designer_plugin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_qwt_designer_plugin.o resources/qrc_qwt_designer_plugin.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/ 
	-$(INSTALL_PROGRAM) "plugins/designer/$(TARGET)" "$(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/$(TARGET)"
	-$(STRIP) --strip-unneeded "$(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/$(TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/$(TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/qwt-6.1.0/plugins/designer/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

