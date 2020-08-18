#include <field/threshold.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/* ------------------------------------------------------------------------- */

void init_threshold_deffn ( field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  memset ( ctx_ptr, 0x00, sizeof ( *ctx_ptr ) );
}

/* ------------------------------------------------------------------------- */

uint8_t is_valid_threshold_deffn ( const field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  return ctx_ptr->value >= ctx_ptr->min
         && ctx_ptr->value <= ctx_ptr->max;
}

/* ------------------------------------------------------------------------- */

uint8_t is_error_low_threshold_deffn ( const field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  return ctx_ptr->value <= ctx_ptr->error;
}

/* ------------------------------------------------------------------------- */

uint8_t is_warn_low_threshold_deffn ( const field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  return ctx_ptr->value <= ctx_ptr->warn;
}

/* ------------------------------------------------------------------------- */

uint8_t is_warn_high_threshold_deffn ( const field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  return ctx_ptr->value >= ctx_ptr->warn;
}

/* ------------------------------------------------------------------------- */

uint8_t is_error_high_threshold_deffn ( const field_threshold_t* ctx_ptr )
{
  assert ( NULL != ctx_ptr );

  return ctx_ptr->value >= ctx_ptr->error;
}

/* ------------------------------------------------------------------------- */

void init_array_threshold_deffn ( field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    init_threshold_deffn ( ctx_ptr++ );
  }
}

/* ------------------------------------------------------------------------- */

uint8_t is_valid_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint8_t result = 1;
  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    result = result && is_valid_threshold_deffn ( ctx_ptr++ );
  }

  return result;
}

/* ------------------------------------------------------------------------- */

uint8_t is_error_low_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint8_t result = 0;
  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    result = result || is_error_low_threshold_deffn ( ctx_ptr++ );
  }

  return result;
}

/* ------------------------------------------------------------------------- */

uint8_t is_warn_low_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint8_t result = 0;
  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    result = result || is_warn_low_threshold_deffn ( ctx_ptr++ );
  }

  return result;
}

/* ------------------------------------------------------------------------- */

uint8_t is_warn_high_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint8_t result = 0;
  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    result = result || is_warn_high_threshold_deffn ( ctx_ptr++ );
  }

  return result;
}

/* ------------------------------------------------------------------------- */

uint8_t is_error_high_array_threshold_deffn ( const field_threshold_t* ctx_ptr, uint16_t n )
{
  assert ( NULL != ctx_ptr && 0 != n );

  uint8_t result = 0;
  uint16_t i;

  for ( i = 0; i < n; ++i )
  {
    result = result || is_error_high_threshold_deffn ( ctx_ptr++ );
  }

  return result;
}

