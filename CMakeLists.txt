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

set(ERP_TEST_PATH tests/sqlTests/erpTests)
set(CRM_TEST_PATH tests/sqlTests/crmTests)
set(ADMIN_TEST_PATH tests/sqlTests/adminTests)

set(QT_DEPS Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)


# macro for setting tests

macro(gen_test TEST_NAME)
  add_executable(${TEST_NAME} ${ARGN})
  target_link_libraries(${TEST_NAME} ${QT_DEPS})
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endmacro()

# macro for setting tests in erpTests
macro(gen_erp_test TEST_NAME TEST_FILE)

  gen_test(${TEST_NAME} ${ERP_TEST_PATH}/${TEST_FILE} ${SQL_TEST_SOURCES})

endmacro()

# macro for setting tests in crmTests
macro(gen_crm_test TEST_NAME TEST_FILE)

  gen_test(${TEST_NAME} ${CRM_TEST_PATH}/${TEST_FILE} ${SQL_TEST_SOURCES})

endmacro()

# macro for setting tests in adminTests
macro(gen_admin_test TEST_NAME TEST_FILE)

  gen_test(${TEST_NAME} ${ADMIN_TEST_PATH}/${TEST_FILE} ${SQL_TEST_SOURCES})

endmacro()

#################################### ERP CONNECTION TESTS #################################

# ctor dtor
gen_erp_test(erp_conn_ctor erpCtor.cpp)


################################### CRM CONNECTION TESTS ##################################

# ctor dtor
gen_crm_test(crm_conn_ctor crmCtor.cpp)
gen_crm_test(crm_add_user crmUser.cpp)

################################## ADMIN CONNECTION TESTS #################################

#ctor dtor
gen_admin_test(admin_conn_ctor adminCtor.cpp)

