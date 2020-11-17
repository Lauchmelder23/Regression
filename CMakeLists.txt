cmake_minimum_required(VERSION 3.10)

project(Regression)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS include/ui)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE source_files
	"src/*.cpp"
)

file(GLOB_RECURSE include_files
	"include/*.hpp"
	"include/*.ui"
)

add_executable(regression
	${include_files}
	${source_files}
)

target_include_directories(regression PRIVATE
	include
	${Qt5_INCLUDE_DIRS}
)

target_link_libraries(regression PRIVATE
	Qt5::Widgets
)

if(WIN32)
	add_custom_command(TARGET regression POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:regression>
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:regression>
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:regression>

		# This is garbage, remove this, Qt just sucks
		COMMAND ${CMAKE_COMMAND} -E copy ${Qt5_DIR}/../../../plugins/platforms/qwindowsd.dll $<TARGET_FILE_DIR:regression>
		COMMAND ${CMAKE_COMMAND} -E copy ${Qt5_DIR}/../../../plugins/platforms/qwindows.dll $<TARGET_FILE_DIR:regression>
	)
endif()