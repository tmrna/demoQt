cmake_minimum_required(VERSION 3.5)

project(demoQt VERSION 0.1 LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Test)
#sql support



set(PROJECT_SOURCES

        main.cpp
        configuration.hpp
######FORMS###########FORMS################## FORMS

##     LOGIN

        forms/login/login.cpp
        forms/login/login.h
        forms/login/login.ui
#---------------------------------------------------------------------------------------------------------

##  SIGNUP
        forms/signup/signup.hpp
        forms/signup/signup.cpp
        forms/signup/signup.ui


## ADMIN SIGNUP

    forms/admin/adminsignup.hpp
    forms/admin/adminsignup.cpp
    forms/admin/adminsignup.ui

## ADMIN LOGIN


## ADMIN HOME


## USER HOME


## CLIENT HOME



#################################     LIB  ################################# LIB

# utilities
        lib/utils/utils.hpp
        lib/utils/utils.cpp

# effects
        lib/styling/effects.hpp
        lib/styling/effects.cpp

# exceptions
        lib/exceptions/sqlException.hpp
        lib/exceptions/sqlException.cpp
#  SQL connections
        lib/sqlConnections/sqlConnection.hpp
        lib/sqlConnections/sqlConnection.cpp

        lib/sqlConnections/erpConnection.hpp
        lib/sqlConnections/erpConnection.cpp

        lib/sqlConnections/crmConnection.hpp
        lib/sqlConnections/crmConnection.cpp

        lib/sqlConnections/adminConnection.hpp
        lib/sqlConnections/adminConnection.cpp

#
#        lib/readWrite/jsonRW.hpp
#        lib/readWrite/jsonRW.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(demoQt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET demoQt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(demoQt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(demoQt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(demoQt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                        Qt${QT_VERSION_MAJOR}::Sql
)


#target_link_libraries(demoQt Qt5::Core Qt5::Quick Qt5::Sql)

set_target_properties(demoQt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS demoQt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(demoQt)
endif()


###################  TESTING ############################################################


enable_testing()


##############################  LIBRARY / DEPS  #############################################
set(SQL_TEST_SOURCES
  
            configuration.hpp
    # exceptions
            lib/exceptions/sqlException.hpp
            lib/exceptions/sqlException.cpp
    #  SQL connections
            lib/sqlConnections/sqlConnection.hpp
            lib/sqlConnections/sqlConnection.cpp

            lib/sqlConnections/erpConnection.hpp
            lib/sqlConnections/erpConnection.cpp

            lib/sqlConnections/crmConnection.hpp
            lib/sqlConnections/crmConnection.cpp

            lib/sqlConnections/adminConnection.hpp
            lib/sqlConnections/adminConnection.cpp
)



set(QT_DEPS Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)


###########################       EXECUTABLES          ###############################

add_executable(erp_conn_ctor ${SQL_TEST_SOURCES} tests/sqlTests/erpTests/erpCtor.cpp
)

add_executable(crm_conn_ctor ${SQL_TEST_SOURCES} tests/sqlTests/crmTests/crmCtor.cpp)

add_executable(admin_conn_ctor ${SQL_TEST_SOURCES} tests/sqlTests/adminTests/adminCtor.cpp)

#########################      DEPS LINK   #####################################

target_link_libraries(erp_conn_ctor ${QT_DEPS})

target_link_libraries(crm_conn_ctor ${QT_DEPS})

target_link_libraries(admin_conn_ctor ${QT_DEPS})


########################     ADDING TESTS  ###################################

add_test(NAME erp_conn_ctor COMMAND erp_conn_ctor)

add_test(NAME crm_conn_ctor COMMAND crm_conn_ctor)

add_test(NAME admin_conn_ctor COMMAND admin_conn_ctor)
