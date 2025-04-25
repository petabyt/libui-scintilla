cmake_minimum_required(VERSION 3.10)
project(libui_scintilla)

add_subdirectory(${PROJECT_SOURCE_DIR}/../libui-dev ${CMAKE_CURRENT_BINARY_DIR}/libui)

set(SCINTILLA_SRC scintilla/src/AutoComplete.cxx scintilla/src/CallTip.cxx scintilla/src/CaseConvert.cxx scintilla/src/CaseFolder.cxx scintilla/src/CellBuffer.cxx scintilla/src/ChangeHistory.cxx scintilla/src/CharacterCategoryMap.cxx scintilla/src/CharacterType.cxx scintilla/src/CharClassify.cxx scintilla/src/ContractionState.cxx scintilla/src/DBCS.cxx scintilla/src/Decoration.cxx scintilla/src/Document.cxx scintilla/src/EditModel.cxx scintilla/src/Editor.cxx scintilla/src/EditView.cxx scintilla/src/Geometry.cxx scintilla/src/Indicator.cxx scintilla/src/KeyMap.cxx scintilla/src/LineMarker.cxx scintilla/src/MarginView.cxx scintilla/src/PerLine.cxx scintilla/src/PositionCache.cxx scintilla/src/RESearch.cxx scintilla/src/RunStyles.cxx scintilla/src/Selection.cxx scintilla/src/Style.cxx scintilla/src/UndoHistory.cxx scintilla/src/UniConversion.cxx scintilla/src/UniqueString.cxx scintilla/src/ViewStyle.cxx scintilla/src/XPM.cxx scintilla/src/ScintillaBase.cxx)

if(WIN32)
	list(APPEND SCINTILLA_SRC scintilla/win32/HanjaDic.cxx scintilla/win32/PlatWin.cxx scintilla/win32/ScintillaWin.cxx win.c)
endif()
if(LINUX)
	list(APPEND SCINTILLA_SRC scintilla/gtk/PlatGTK.cxx scintilla/gtk/ScintillaGTKAccessible.cxx scintilla/gtk/ScintillaGTK.cxx scintilla/gtk/scintilla-marshal.c gtk.cpp)
endif()

get_target_property(libui_source_dir LibUI::LibUI SOURCE_DIR)

add_library(libui_scintilla STATIC ${SCINTILLA_SRC})
target_include_directories(libui_scintilla
	PUBLIC ${PROJECT_SOURCE_DIR}/scintilla/include
	PRIVATE ${PROJECT_SOURCE_DIR}/scintilla/src ${PROJECT_SOURCE_DIR}/scintilla/win32
	PRIVATE $<TARGET_PROPERTY:LibUI::LibUI,INTERFACE_INCLUDE_DIRECTORIES>
	PRIVATE ${libui_source_dir}
)
target_compile_definitions(libui_scintilla PRIVATE -DGTK -DNDEBUG)
