
@if (DOXYGEN_PROJECT)
@defgroup Semihosting
@endif

# Semihosting

## Overview

Implementation of Semihosting GetChar/SendChar.

### What is Semihosting?

Semihosting provides a mechanism for code running on the MCU to put/get data to/from IDE through USB Adapter.

### How to use:

- enable Semihosting Project properties.
- checked "Semihosting" in components page
- checked "Retarget printf" in components page, then implement PrintChar in printf.c <Optional >
- use Semihostting API or Retargeted printf/scanf to transmit data between MCU & IDE

## API Reference

- SH_SendChar()	
Transmit a char on semihosting mode.

- SH_SendString()	
Transmit a null-terminated string on semihosting mode.

- SH_GetChar()	
Read a char on semihosting mode.

- SH_DoCommand()	
Semihosting functions prototype


