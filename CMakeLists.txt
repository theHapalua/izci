cmake_minimum_required(VERSION 3.10)
project(Izci)

set(EXEC_INSTALL_DIR /usr/local/bin)

set(FLATPAK_PREFIX ${CMAKE_CURRENT_LIST_DIR}/flatfiles)
set(LIBRE_OFFICE_FILE org.libreoffice.LibreOffice.flatpakref)
set(WPS_OFFICE_FILE com.wps.Office.flatpakref)
set(ATOM_FILE io.atom.Atom.flatpakref)
set(GIMP_FILE org.gimp.GIMP.flatpakref)
set(INKSCAPE_FILE org.inkscape.Inkscape.flatpakref)
set(BLENDER_FILE org.blender.Blender.flatpakref)
set(AUDACITY_FILE org.audacityteam.Audacity.flatpakref)
set(LMMS_FILE io.lmms.LMMS.flatpakref)
set(KDENLIVE_FILE org.kde.kdenlive.flatpakref)
set(SYNFIG_FILE org.synfig.SynfigStudio.flatpakref)
set(BOXES_FILE org.gnome.Boxes.flatpakref)
configure_file(cmake/config.h.in ${CMAKE_CURRENT_LIST_DIR}/src/config.h @ONLY)

include(GNUInstallDirs)

add_executable(izci src/main.cpp src/window.h src/window.cpp src/installer.h src/installer.cpp)

find_Package( PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
target_include_directories(izci PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_directories(izci PUBLIC ${GTKMM_LIBRARY_DIRS})
target_link_libraries(izci PUBLIC ${GTKMM_LIBRARIES})
install(TARGETS izci RUNTIME DESTINATION bin)

