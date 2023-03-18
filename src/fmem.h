#ifndef __FMEM_H__ 
#define __FMEM_H__


#include <stdint.h>
#include <string.h>
#include <stdbool.h>


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  X-Macros
 *
 *  -   FMEM_CREATE_ENUM            A nested macro to expand enumerators in a enumeration type (except addrs)
 *  -   FMEM_ENUM_TO_STR            A nested macro to expand case statements per enumerator (except addrs)
 *  -   FMEM_PRINT_ENUMS            A nested macro to expand printf's per enumerator (except addrs)
 *
 *  Unit Testing Only
 *
 *  -   FMEM_INIT                   A nested macro to expand on bracket initialization (except addrs)
 *  -   FMEM_REG_TO_STR_TESTS       A nested macro to expand test cases for fmem_reg_to_str
 *  -   FMEM_INIT_REG_TESTS         A nested macro to expand test cases for check intialization
 *  -   FMEM_WRITE_REG_TEST         A nested macro to expand test cases for fmem_write_reg
 *  -   FMEM_READ_REG_TESTS         A nested macro to expand test cases for fmem_read_reg
 *  -------------------------------------------------------------------------------------------------------------------
 */


#define FMEM_FOR_EACH_ADDR(DO)  \
    DO(ADDR0,)                  \
    DO(ADDR1,)                  \
    DO(ADDR2,)                  \
    DO(ADDR3,)                  \
    DO(ADDR4,)                  \
    DO(ADDR5,)                  \
    DO(ADDR6,)                  \
    DO(ADDR7,)                  \
    DO(ADDR8,)                  \
    DO(ADDR9,)


#define FMEM_FOR_EACH_ENUM(DO) FMEM_FOR_EACH_ADDR(DO) DO(ADDRS,)


#define FMEM_CREATE_ENUM(addr, addr_value, ...) \
    addr addr_value,


#define FMEM_ENUM_TO_STR(addr, addr_value, ...) \
    case addr: return #addr;


#define FMEM_PRINT_ENUMS(addr, addr_value, ...) \
    printf ( #addr " = %d\n", addr );


#define FMEM_INIT(addr, addr_value, ...) 0,


#define FMEM_REG_TO_STR_TESTS(addr, addr_value, ...) \
    assert(strcmp(fmem_reg_to_str(addr),#addr)==0);


#define FMEM_INIT_REG_TESTS(addr, addr_value, ...) \
    assert(fmem_read_reg(&fmem_fake_memory, addr) == 0);


#define FMEM_WRITE_REG_TEST(addr, addr_value, ...) \
    assert(fmem_write_reg(&fmem_fake_memory, addr, 1) == true);


#define FMEM_READ_REG_TESTS(addr, addr_value, ...) \
    assert(fmem_read_reg(&fmem_fake_memory, addr) == 1);


typedef enum 
{ 
    FMEM_FOR_EACH_ENUM(FMEM_CREATE_ENUM) 
} fmem_addr_t;


typedef struct
{
    uint32_t mblk[ADDRS];
    uint32_t base;
} fmem_t;


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


uint32_t fmem_read_reg ( fmem_t * ptr, fmem_addr_t addr );


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


bool fmem_write_reg ( fmem_t * ptr, fmem_addr_t addr, uint32_t val );


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


const char * fmem_reg_to_str ( fmem_addr_t addr );


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


void fmem_test ();


#endif /*__FMEM_H__*/
