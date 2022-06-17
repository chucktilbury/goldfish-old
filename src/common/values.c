/**
 * @file values.c
 * @brief Implement values and all of the operations required for them.
 */
#include "values.h"
#include "errors.h"

Value castValue(ValType type, Value val, bool isConst)
{
    Value retv;
    switch(type) {
        case UINT8: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = UINT8;
                            retv.data.unum8 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = UINT8;
                            if(val.data.unum16 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = UINT8;
                            if(val.data.unum32 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = UINT8;
                            if(val.data.unum64 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = UINT8;
                            retv.data.unum8 = (uint8_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = UINT8;
                            if(val.data.snum16 > UINT8_MAX || val.data.snum16 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = UINT8;
                            if(val.data.snum32 > UINT8_MAX || val.data.snum32 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = UINT8;
                            if(val.data.snum64 > UINT8_MAX || val.data.snum64 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = UINT8;
                            if(val.data.fnum > UINT8_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = UINT8;
                            if(val.data.dnum > UINT8_MAX || val.data.dnum < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = UINT8;
                            retv.data.unum8 = (val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = UINT8;
                            if(val.data.addr > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case UINT16: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = UINT16;
                            retv.data.unum16 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = UINT16;
                            retv.data.unum16 = val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = UINT16;
                            if(val.data.unum32 > UINT16_MAX)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = UINT16;
                            if(val.data.unum64 > UINT16_MAX)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = UINT16;
                            retv.data.unum16 = (uint16_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = UINT16;
                            retv.data.unum16 = (uint16_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = UINT16;
                            if(val.data.snum32 > UINT16_MAX || val.data.snum32 < 0)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = UINT16;
                            if(val.data.snum64 > UINT16_MAX || val.data.snum64 < 0)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = UINT16;
                            if(val.data.fnum > UINT16_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = UINT16;
                            if(val.data.dnum > UINT16_MAX || val.data.dnum < 0)
                                warning("value truncated");
                            retv.data.unum16 = (uint16_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = UINT16;
                            retv.data.unum16 = (val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = UINT16;
                            if(val.data.addr > UINT16_MAX)
                                warning("value truncated");
                            retv.data.unum16 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case UINT32: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = UINT32;
                            retv.data.unum32 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = UINT32;
                            if(val.data.unum16 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum32 = (uint32_t)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = UINT32;
                            retv.data.unum32 = (uint32_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = UINT32;
                            if(val.data.unum64 > UINT32_MAX)
                                warning("value truncated");
                            retv.data.unum32 = (uint32_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = UINT32;
                            retv.data.unum32 = (uint32_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = UINT32;
                            retv.data.unum32 = (uint32_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = UINT32;
                            retv.data.unum32 = (uint32_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = UINT32;
                            if(val.data.snum64 > UINT32_MAX || val.data.snum64 < 0)
                                warning("value truncated");
                            retv.data.unum32 = (uint32_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = UINT32;
                            if(val.data.fnum > UINT32_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum32 = (uint32_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = UINT32;
                            if(val.data.dnum > UINT32_MAX || val.data.dnum < 0)
                                warning("value truncated");
                            retv.data.unum32 = (uint32_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = UINT32;
                            retv.data.unum32 = (val.data.unum8)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = UINT32;
                            retv.data.unum32 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case UINT64: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = UINT64;
                            retv.data.unum64 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = UINT64;
                            retv.data.unum64 = (uint8_t)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = UINT64;
                            retv.data.unum64 = (uint8_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = UINT64;
                            retv.data.unum64 = (uint8_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = UINT64;
                            retv.data.unum64 = (int64_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = UINT64;
                            retv.data.unum64 = (int64_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = UINT64;
                            retv.data.unum64 = (int64_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = UINT64;
                            retv.data.unum64 = (int64_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = UINT64;
                            if(val.data.fnum > UINT64_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum64 = (int64_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = UINT64;
                            if(val.data.dnum > UINT64_MAX || val.data.dnum < 0)
                                warning("value truncated");
                            retv.data.unum64 = (int64_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = UINT64;
                            retv.data.unum64 = (val.data.unum8)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = UINT64;
                            retv.data.unum64 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case INT8: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = INT8;
                            retv.data.snum8 = (int8_t)val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = INT8;
                            if(val.data.unum16 > INT8_MAX)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = INT8;
                            if(val.data.unum32 > INT8_MAX)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = INT8;
                            if(val.data.unum64 > INT8_MAX)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = INT8;
                            retv.data.snum8 = (int8_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = INT8;
                            if(val.data.snum16 > INT8_MAX || val.data.snum16 < INT8_MIN)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = INT8;
                            if(val.data.snum32 > INT8_MAX || val.data.snum32 < INT8_MIN)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = INT8;
                            if(val.data.snum64 > INT8_MAX || val.data.snum64 < INT8_MIN)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = INT8;
                            if(val.data.fnum > INT8_MAX || val.data.fnum < INT8_MIN)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = INT8;
                            if(val.data.dnum > INT8_MAX || val.data.dnum < INT8_MIN)
                                warning("value truncated");
                            retv.data.snum8 = (int8_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = INT8;
                            retv.data.snum8 = (val.data.boolean)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = INT8;
                            if(val.data.addr > INT8_MAX)
                                warning("value truncated");
                            retv.data.snum8 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case INT16: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = INT16;
                            retv.data.snum16 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = INT16;
                            retv.data.snum16 = val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = INT16;
                            if(val.data.unum32 > UINT16_MAX)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = INT16;
                            if(val.data.unum64 > INT16_MAX)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = INT16;
                            retv.data.snum16 = val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = INT16;
                            retv.data.snum16 = val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = INT16;
                            if(val.data.snum32 > INT16_MAX || val.data.snum32 < 0)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = INT16;
                            if(val.data.snum64 > INT16_MAX || val.data.snum64 < 0)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = INT16;
                            if(val.data.fnum > INT16_MAX || val.data.fnum < INT16_MIN)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = INT16;
                            if(val.data.dnum > INT16_MAX || val.data.dnum < INT16_MIN)
                                warning("value truncated");
                            retv.data.snum16 = (int16_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = INT16;
                            retv.data.snum16 = (val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = INT16;
                            if(val.data.addr > INT16_MAX)
                                warning("value truncated");
                            retv.data.snum16 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case INT32: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = INT32;
                            if(val.data.unum64 > INT32_MAX)
                                warning("value truncated");
                            retv.data.snum32 = (int32_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = INT32;
                            retv.data.snum32 = val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = INT32;
                            if(val.data.snum64 > INT32_MAX || val.data.snum64 < INT32_MIN)
                                warning("value truncated");
                            retv.data.snum32 = (int32_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = INT32;
                            if(val.data.fnum > INT32_MAX || val.data.fnum < INT32_MIN)
                                warning("value truncated");
                            retv.data.snum32 = (int32_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = INT32;
                            if(val.data.dnum > INT32_MAX || val.data.dnum < INT32_MIN)
                                warning("value truncated");
                            retv.data.snum32 = (int32_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = INT32;
                            retv.data.snum32 = (val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = INT32;
                            retv.data.snum32 = (uint32_t)val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case INT64: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = INT64;
                            retv.data.snum64 = (uint64_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = INT64;
                            if(val.data.fnum > INT64_MAX || val.data.fnum < INT64_MIN)
                                warning("value truncated");
                            retv.data.snum64 = (int64_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = INT64;
                            if(val.data.dnum > INT64_MAX || val.data.dnum < INT64_MIN)
                                warning("value truncated");
                            retv.data.snum64 = (int64_t)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = INT64;
                            retv.data.snum64 = (val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = INT64;
                            retv.data.snum64 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case FLOAT: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = FLOAT;
                            if(val.data.dnum > FLT_MAX || val.data.dnum < FLT_MIN)
                                warning("value truncated");
                            retv.data.fnum = (float)val.data.dnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)(val.data.boolean)? 1.0: 0.0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = FLOAT;
                            retv.data.fnum = (float)val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case DOUBLE: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)(val.data.boolean)? 1: 0;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = DOUBLE;
                            retv.data.dnum = (double)val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case BOOL: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.unum8 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.unum16 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.unum32 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.unum64 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.snum8 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.snum16 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.snum32 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.snum64 == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.fnum != 0.0)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.fnum != 0.0)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = BOOL;
                            retv.data.boolean = val.data.boolean;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = BOOL;
                            retv.data.boolean = (val.data.addr == 0)? false: true;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case ADDRESS: {
                switch(val.type) {
                    case UINT8: {
                            retv.type = UINT8;
                            retv.data.unum8 = val.data.unum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT16: {
                            retv.type = UINT8;
                            if(val.data.unum16 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT32: {
                            retv.type = UINT8;
                            if(val.data.unum32 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case UINT64: {
                            retv.type = UINT8;
                            if(val.data.unum64 > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.unum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT8: {
                            retv.type = UINT8;
                            retv.data.unum8 = (uint8_t)val.data.snum8;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT16: {
                            retv.type = UINT8;
                            if(val.data.snum16 > UINT8_MAX || val.data.snum16 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum16;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT32: {
                            retv.type = UINT8;
                            if(val.data.snum32 > UINT8_MAX || val.data.snum32 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum32;
                            retv.isConst = isConst;
                        }
                        break;
                    case INT64: {
                            retv.type = UINT8;
                            if(val.data.snum64 > UINT8_MAX || val.data.snum64 < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.snum64;
                            retv.isConst = isConst;
                        }
                        break;
                    case FLOAT: {
                            retv.type = UINT8;
                            if(val.data.fnum > UINT8_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case DOUBLE: {
                            retv.type = UINT8;
                            if(val.data.fnum > UINT8_MAX || val.data.fnum < 0)
                                warning("value truncated");
                            retv.data.unum8 = (uint8_t)val.data.fnum;
                            retv.isConst = isConst;
                        }
                        break;
                    case BOOL: {
                            retv.type = UINT8;
                            retv.data.unum8 = (val.data.unum8)? true: false;
                            retv.isConst = isConst;
                        }
                        break;
                    case ADDRESS: {
                            retv.type = UINT8;
                            if(val.data.addr > UINT8_MAX)
                                warning("value truncated");
                            retv.data.unum8 = val.data.addr;
                            retv.isConst = isConst;
                        }
                        break;
                    case STRING:
                    case DICT:
                    case LIST:
                    case USRTYPE:
                        warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    case ERROR:
                    case NOTHING:
                        error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
                        break;
                    default:
                        fatal("unknown casting type");
                }
            }
            break;
        case STRING:
        case DICT:
        case LIST:
        case USRTYPE:
            warning("casting from %s to %s is not implemented", valTypeToStr(type), valTypeToStr(val.type));
            break;
        case ERROR:
        case NOTHING:
            error("casting from %s to %s is invalid", valTypeToStr(type), valTypeToStr(val.type));
            break;
        default:
            fatal("unknown casting type");
    }

    return retv;
}

void printVal(Value val)
{
    printf("%s: ", valTypeToStr(val.type));
    switch(val.type) {
        case ERROR: printf("<ERROR>"); break;
        case NOTHING: printf("<NOTHING>"); break;
        case UINT8: printf("<0x%02X>", val.data.unum8); break;
        case UINT16: printf("<0x%04X>", val.data.unum16); break;
        case UINT32: printf("<0x%08X>", val.data.unum32); break;
        case UINT64: printf("<0x%016lX>", val.data.unum64); break;
        case INT8: printf("<%d>", val.data.snum8); break;
        case INT16: printf("<%d>", val.data.snum16); break;
        case INT32: printf("<%d>", val.data.snum32); break;
        case INT64: printf("<%ld>", val.data.snum64); break;
        case FLOAT: printf("<%0.3f>", val.data.fnum); break;
        case DOUBLE: printf("<%0.03lf>", val.data.dnum); break;
        case BOOL: printf("<%s>", val.data.boolean? "true": "false"); break;
        case ADDRESS: printf("<0x%08X>", val.data.addr); break;
        case STRING: printf("<defer>"); break;
        case DICT: printf("<defer>"); break;
        case LIST: printf("<defer>"); break;
        case USRTYPE: printf("<defer>"); break;
        default: printf("UNKNOWN"); break;
    }
    printf("\n");
}

const char* valTypeToStr(ValType type)
{
    return (type == ERROR)? "ERROR":
            (type == NOTHING)? "NOTHING":
            (type == UINT8)? "UINT8":
            (type == UINT16)? "UINT16":
            (type == UINT32)? "UINT32":
            (type == UINT64)? "UINT64":
            (type == INT8)? "INT8":
            (type == INT16)? "INT16":
            (type == INT32)? "INT32":
            (type == INT64)? "INT64":
            (type == FLOAT)? "FLOAT":
            (type == DOUBLE)? "DOUBLE":
            (type == BOOL)? "BOOL":
            (type == ADDRESS)? "ADDRESS":
            (type == STRING)? "STRING":
            (type == DICT)? "DICT":
            (type == LIST)? "LIST":
            (type == USRTYPE)? "USRTYPE":"UNKNOWN";
}

#if 0
/*
 * These tables are 2 dimension which implements logic that compares two
 * types and then returns another type that is the result of that comparison.
 * The left side is the column and the right side is the row.
 */
static ValType promotion_table[18][18] = {
/*               ERROR,   NOTHING, UINT8,   UINT16,  UINT32,  UINT64,  INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, STRING,  DICT,    LIST,    USRTYPE, */
/* ERROR   */  { ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,    ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR},
/* NOTHING */  { ERROR,   NOTHING, ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,    ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* UINT8   */  { ERROR,   ERROR,   UINT8,   UINT16,  UINT32,  UINT64,  INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT16  */  { ERROR,   ERROR,   UINT16,  UINT16,  UINT32,  UINT64,  INT16,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT32  */  { ERROR,   ERROR,   UINT32,  UINT32,  UINT32,  UINT64,  INT32,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT64  */  { ERROR,   ERROR,   UINT64,  UINT64,  UINT64,  UINT64,  INT64,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT8    */  { ERROR,   ERROR,   INT8,    INT16,   INT32,   INT64,   INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT16   */  { ERROR,   ERROR,   INT16,   INT16,   INT32,   INT64,   INT16,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT32   */  { ERROR,   ERROR,   INT32,   INT32,   INT32,   INT64,   INT32,   INT32,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT64   */  { ERROR,   ERROR,   INT64,   INT64,   INT64,   INT64,   INT64,   INT64,   INT64,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* FLOAT   */  { ERROR,   ERROR,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,    FLOAT,   FLOAT,   DOUBLE,  BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* DOUBLE  */  { ERROR,   ERROR,   DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,   DOUBLE,  DOUBLE,  DOUBLE,  BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* BOOL    */  { ERROR,   ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* ADDRESS */  { ERROR,   ERROR,   ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS,  ADDRESS, ERROR,   ERROR,   ERROR,   ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* STRING  */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   STRING,  DEFER,   DEFER,   DEFER},
/* DICT    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DICT,    DEFER,   DEFER},
/* LIST    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   LIST,    DEFER},
/* USRTYPE */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   USRTYPE},
};

static ValType arith_table[18][18] = {
/*               ERROR,   NOTHING, UINT8,   UINT16,  UINT32,  UINT64,  INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, STRING,  DICT,    LIST,    USRTYPE, */
/* ERROR   */  { ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,    ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR},
/* NOTHING */  { ERROR,   NOTHING, ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,    ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* UINT8   */  { ERROR,   ERROR,   UINT8,   UINT16,  UINT32,  UINT64,  INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT16  */  { ERROR,   ERROR,   UINT16,  UINT16,  UINT32,  UINT64,  INT16,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT32  */  { ERROR,   ERROR,   UINT32,  UINT32,  UINT32,  UINT64,  INT32,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* UINT64  */  { ERROR,   ERROR,   UINT64,  UINT64,  UINT64,  UINT64,  INT64,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT8    */  { ERROR,   ERROR,   INT8,    INT16,   INT32,   INT64,   INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT16   */  { ERROR,   ERROR,   INT16,   INT16,   INT32,   INT64,   INT16,   INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT32   */  { ERROR,   ERROR,   INT32,   INT32,   INT32,   INT64,   INT32,   INT32,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* INT64   */  { ERROR,   ERROR,   INT64,   INT64,   INT64,   INT64,   INT64,   INT64,   INT64,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* FLOAT   */  { ERROR,   ERROR,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,   FLOAT,    FLOAT,   FLOAT,   DOUBLE,  BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* DOUBLE  */  { ERROR,   ERROR,   DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,  DOUBLE,   DOUBLE,  DOUBLE,  DOUBLE,  BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* BOOL    */  { ERROR,   ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    ERROR,   DEFER,   DEFER,   DEFER,   DEFER},
/* ADDRESS */  { ERROR,   ERROR,   ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS, ADDRESS,  ADDRESS, ERROR,   ERROR,   ERROR,   ADDRESS, DEFER,   DEFER,   DEFER,   DEFER},
/* STRING  */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   STRING,  DEFER,   DEFER,   DEFER},
/* DICT    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DICT,    DEFER,   DEFER},
/* LIST    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   LIST,    DEFER},
/* USRTYPE */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   USRTYPE},
};

// This is magnitude, not equality. Equality and magnitude of numbers is
// clear. There can only be ERROR, BOOL, or DEFER values in this table.
static ValType comp_table[18][18] = {
/*               ERROR,   NOTHING, UINT8,   UINT16,  UINT32,  UINT64,  INT8,    INT16,   INT32,    INT64,   FLOAT,   DOUBLE,  BOOL,    ADDRESS, STRING,  DICT,    LIST,    USRTYPE, */
/* ERROR   */  { ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,    ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR,   ERROR},
/* NOTHING */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* UINT8   */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* UINT16  */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* UINT32  */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* UINT64  */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* INT8    */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* INT16   */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* INT32   */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* INT64   */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* FLOAT   */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* DOUBLE  */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* BOOL    */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* ADDRESS */  { ERROR,   BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    BOOL,     BOOL,    BOOL,    BOOL,    BOOL,    BOOL,    DEFER,   DEFER,   DEFER,   DEFER},
/* STRING  */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER},
/* DICT    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER},
/* LIST    */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER},
/* USRTYPE */  { ERROR,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,    DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER,   DEFER},
};


void setValType(Value value, ValType type) { value.type = type; }
ValType getValType(Value value) { return value.type; }

void setValConst(Value value, bool state) { value.isConst = state; }
bool getValConst(Value value) { return value.isConst; }


void setValUnum8(Value value, uint8_t val) { value.data.unum8 = val; }
void setValUnum16(Value value, uint16_t val) { value.data.unum16 = val; }
void setValUnum32(Value value, uint32_t val) { value.data.unum32 = val; }
void setValUnum64(Value value, uint64_t val) { value.data.unum64 = val; }

void setValSnum8(Value value, int8_t val) { value.data.snum8 = val; }
void setValSnum16(Value value, int16_t val) { value.data.snum16 = val; }
void setValSnum32(Value value, int32_t val) { value.data.snum32 = val; }
void setValSnum64(Value value, int64_t val) { value.data.snum64 = val; }

void setValFnum(Value value, float val) { value.data.fnum = val; }
void setValDnum(Value value, double val) { value.data.dnum = val; }
void setValBool(Value value, bool val) { value.data.boolean = val; }
void setValAddr(Value value, uint32_t val) { value.data.addr = val; }

void setValStr(Value value, int val) { value.data.str = val; }
void setValDict(Value value, int val) { value.data.dict = val; }
void setValList(Value value, int val) { value.data.list = val; }
void setValUsrtype(Value value, int val) { value.data.usrtype = val; }

uint8_t getValUnum8(Value value) { return value.data.unum8; }
uint16_t getValUnum16(Value value) { return value.data.unum16; }
uint32_t getValUnum32(Value value) { return value.data.unum32; }
uint64_t getValUnum64(Value value) { return value.data.unum64; }

int8_t getValSnum8(Value value) { return value.data.snum8; }
int16_t getValSnum16(Value value) { return value.data.snum16; }
int32_t getValSnum32(Value value) { return value.data.snum32; }
int64_t getValSnum64(Value value) { return value.data.snum64; }

float getValFnum(Value value) { return value.data.fnum; }
double getValDnum(Value value) { return value.data.dnum; }
bool getValBool(Value value) { return value.data.boolean; }
uint32_t getValAddr(Value value) { return value.data.addr; }

int getValStr(Value value) { return value.data.str; }
int getValDict(Value value) { return value.data.dict; }
int getValList(Value value) { return value.data.list; }
int getValUsrtype(Value value) { return value.data.usrtype; }

ValType getPromotionResult(ValType to, ValType from) { return promotion_table[to][from]; }
ValType getArithResultType(ValType left, ValType right) { return arith_table[left][right]; }
ValType getCompResultType(ValType left, ValType right) { return comp_table[left][right]; }

#endif

