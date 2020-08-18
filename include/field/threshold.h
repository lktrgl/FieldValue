#ifndef THRESHOLD_H_INCLUDED
#define THRESHOLD_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct field_threshold_tag
{
  uint16_t value;

  uint16_t min;

  uint16_t warn;
  uint16_t error;

  uint16_t max;
} field_threshold_t;

/* ------------------------------------------------------------------------- */

void init_threshold_deffn ( field_threshold_t* ctx_ptr );
uint8_t is_valid_threshold_deffn ( const field_threshold_t* ctx_ptr );
uint8_t is_error_low_threshold_deffn ( const field_threshold_t* ctx_ptr );
uint8_t is_warn_low_threshold_deffn ( const field_threshold_t* ctx_ptr );
uint8_t is_warn_high_threshold_deffn ( const field_threshold_t* ctx_ptr );
uint8_t is_error_high_threshold_deffn ( const field_threshold_t* ctx_ptr );

/* ------------------------------------------------------------------------- */

void init_array_threshold_deffn ( field_threshold_t* ctx_ptr, uint16_t n );
uint8_t is_valid_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n );
uint8_t is_error_low_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n );
uint8_t is_warn_low_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n );
uint8_t is_warn_high_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n );
uint8_t is_error_high_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n );

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* THRESHOLD_H_INCLUDED */
