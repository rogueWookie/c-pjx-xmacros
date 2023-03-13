#include <stdio.h>
#include <assert.h>
#include "fmem.h"


/*
 *   Enum        Address             byte           byte           byte           byte
 *  
 *  ADDR0   |  0x0000_0000  |    0b0000_0000    0b0000_0000    0b0000_0000    0b0000_0000
 *  ADDR1   |  0x0000_0004  |    0b0000_0000    0b0000_0000    0b0000_0000    0b0000_0000
 *   ...            ...               ...            ...            ...            ...
 */


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


uint32_t fmem_read_reg ( fmem_t * ptr, fmem_addr_t addr )
{
    return ptr->mblk[ (addr - ptr->base) ];
}


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


bool fmem_write_reg ( fmem_t * ptr, fmem_addr_t addr, uint32_t val )
{
    bool ret = true;
    
    if ( (NULL == ptr) || (ADDRS <= addr) )
    {
        ret = false;
    }
    else
    {
        ptr->mblk[ (addr - ptr->base) ] = val;
    }

    return ret;
}


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


const char * fmem_reg_to_str ( fmem_addr_t addr )
{
    switch ( addr )
    {
        FMEM_FOR_EACH_ADDR(FMEM_ENUM_TO_STR)
        case ADDRS: return "UNKNOWN_ADDRESS";
        default:    return "UNKNOWN_ADDRESS";
    }
}


/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 */


void fmem_test ()
{
    fmem_t fmem_fake_memory = { {FMEM_FOR_EACH_ADDR(FMEM_INIT)}, ADDR0 };

    FMEM_FOR_EACH_ADDR(FMEM_PRINT_ENUMS)
    FMEM_FOR_EACH_ADDR(FMEM_REG_TO_STR_TESTS)
    FMEM_FOR_EACH_ADDR(FMEM_INIT_REG_TESTS)
    FMEM_FOR_EACH_ADDR(FMEM_WRITE_REG_TEST)
    FMEM_FOR_EACH_ADDR(FMEM_READ_REG_TESTS)
}
