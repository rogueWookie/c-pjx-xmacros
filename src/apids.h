#ifndef __APIDS_H__
#define __APIDS_H__


#include <stdio.h>
#include <assert.h>
#include <string.h>


/*
 *  -------------------------------------------------------------------------------------------------------------------
 * X-Macros
 *
 *  -   APIDS_CREATE_ENUMS          A nested macro to expand enumerators in a enumeration type (except manx num)
 *  -   APIDS_PRINT_ENUMS           A nested macro to expand printf's per enumerator (except max num)
 *  -   APIDS_CREATE_SWITCH_CASE    A nested macro to expand case statements per enumerator (except max num)
 *
 *  Unit Testing Only
 *
 *  -   APIDS_TEST_ENUM_TO_STR      A nested macro to expand unit tests per enumerator (except max num)
 *  -------------------------------------------------------------------------------------------------------------------
 */


#define APIDS_FOR_EACH_APID(DO) \
    DO(APID_ASDF_00,)           \
    DO(APID_ASDF_01,)           \
    DO(APID_ASDF_02,)           \
    DO(APID_ASDF_03,)           \
    DO(APID_ASDF_04,)           \
    DO(APID_ASDF_05,)           \
    DO(APID_ASDF_06,)

#define APIDS_FOR_EACH_ENUM(DO) \
    APIDS_FOR_EACH_APID(DO) DO(APIDS_MAX_NUM,)

#define APIDS_CREATE_ENUMS(apid, apid_value, ...) \
    apid apid_value,


#define APIDS_PRINT_ENUMS(apid, apid_value, ...) \
    printf(#apid " = %d\n", apid);


#define APIDS_CREATE_SWITCH_CASE(apid, apid_value, ...) \
    case apid: return #apid;


#define APIDS_TEST_ENUM_TO_STR(apid, apid_value, ...) \
    assert(strcmp(apids_enum_to_str(apid),#apid)==0);


typedef enum 
{
    APIDS_FOR_EACH_ENUM(APIDS_CREATE_ENUMS)
} APID_e;


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


const char * apids_enum_to_str ( APID_e apid );


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


void apid_test ();


#endif  /*__XMACROS_H__*/
