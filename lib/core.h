#ifndef __STARm_CORE_H
#define __STARm_CORE_H

#include <stdio.h>

#ifdef STARm_F0
  #include "stm32f0xx.h"
#elif  STARm_F1
  #include "stm32f1xx.h"
#elif  STARm_F3
  #include "stm32f3xx.h"
#elif  STARm_L0
  #include "stm32l0xx.h"
#endif

// Project includes.
#include "register_macros.h"

// Global macro definitions.
#define pSTATUS_ERR (0)

// System clock speed; initial value depends on the chip.
extern volatile uint32_t sys_clock_hz;

// Class declarations for basic structures common
// to many peripherals.
/*
 * Input/Output class. This covers things that read and/or write
 * data between devices. I2C, SPI, UART, etc.
 */
class pIO {
public:
  pIO();
  // Common read/write methods.
  virtual unsigned read(void);
  virtual void     write(unsigned dat);
  // Common peripheral control methods.
  virtual void     clock_en(void);
  virtual void     reset(void);
  virtual void     disable(void);
  virtual int      get_status(void);
protected:
  // Expected peripheral status.
  int status = pSTATUS_ERR;
private:
};

#endif
