#ifndef RANGE_H_INCLUDED
#define RANGE_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct field_range_tag
{
  uint16_t value;

  uint16_t min;

  uint16_t error_low;
  uint16_t warn_low;
  uint16_t warn_high;
  uint16_t error_high;

  uint16_t max;
} field_range_t;

/* ------------------------------------------------------------------------- */

void init_range_deffn ( field_range_t* ctx_ptr );
uint8_t is_valid_range_deffn ( const field_range_t* ctx_ptr );
uint8_t is_error_low_range_deffn ( const field_range_t* ctx_ptr );
uint8_t is_warn_low_range_deffn ( const field_range_t* ctx_ptr );
uint8_t is_warn_high_range_deffn ( const field_range_t* ctx_ptr );
uint8_t is_error_high_range_deffn ( const field_range_t* ctx_ptr );

/* ------------------------------------------------------------------------- */

void init_array_range_deffn ( field_range_t* ctx_ptr, uint16_t n );
uint8_t is_valid_array_range_deffn ( const field_range_t* ctx_ptr, uint16_t n );
uint8_t is_error_low_array_range_deffn ( const field_range_t* ctx_ptr, uint16_t n );
uint8_t is_warn_low_array_range_deffn ( const field_range_t* ctx_ptr, uint16_t n );
uint8_t is_warn_high_array_range_deffn ( const field_range_t* ctx_ptr, uint16_t n );
uint8_t is_error_high_array_range_deffn ( const field_range_t* ctx_ptr, uint16_t n );

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* RANGE_H_INCLUDED */
