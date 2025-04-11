```c
#include <stdio.h>
#include <math.h>
#include <ieee754.h>

#define LOG2_10 3.321928095 // Approximate value of log2(10)
#define EPSILON 1e-9        // Small value to compare floating-point numbers

#define is_zero(x) (fabs(x) < EPSILON)

int max_digits_left = 5;    // Maximum digits to the left of the decimal point
int max_zeros_right = 3;    // Maximum consecutive zeros to the right of the decimal point before switching to scientific notation

void print_real(double number, int width, int decimal_places)
{
    int magnitude;
    double fractional_part, temp;
    char format_specifier[8];
    char format_type[3] = {'l', 0, 0};
    union ieee754_double *double_representation;

    double_representation = (union ieee754_double*)&number;
    magnitude = (double_representation->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;

    if (number == 0)
        magnitude = 0;

    if ((magnitude > max_digits_left - 1) || (magnitude < -max_zeros_right)) {
        format_type[1] = 'e'; // Use scientific notation
        temp = number / pow(10, magnitude);
        fractional_part = temp - floor(temp);
    } else {
        format_type[1] = 'f'; // Use fixed-point notation
        fractional_part = number - floor(number);
    }

    if (is_zero(fractional_part))
        decimal_places = 0;

    if (width == 0) {
        snprintf(format_specifier, 8, "%%.%d%s", decimal_places, format_type);
    } else {
        snprintf(format_specifier, 8, "%%%d.%d%s", width, decimal_places, format_type);
    }

    printf(format_specifier, number);
}
```

1. **Including Headers and Defining Constants:**
   - `#include <stdio.h>`: Includes the standard input-output library for functions like `printf`.
   - `#include <math.h>`: Includes the math library for mathematical functions like `fabs`, `pow`, and `floor`.
   - `#include <ieee754.h>`: Includes definitions related to the IEEE 754 floating-point standard.
   - `#define LOG2_10 3.321928095`: Defines the constant value of log base 2 of 10, used for magnitude calculations.
   - `#define EPSILON 1e-9`: Defines a small threshold value to compare floating-point numbers for equality.

2. **Defining Macros and Global Variables:**
   - `#define is_zero(x) (fabs(x) < EPSILON)`: Macro to check if a floating-point number is effectively zero by comparing it to `EPSILON`.
   - `int max_digits_left = 5;`: Sets the maximum number of digits allowed to the left of the decimal point before switching to scientific notation.
   - `int max_zeros_right = 3;`: Sets the maximum number of consecutive zeros to the right of the decimal point before switching to scientific notation.

3. **Function Definition:**
   - `void print_real(double number, int width, int decimal_places)`: Defines the function `print_real` that takes a double `number`, an integer `width` for the total width of the output, and an integer `decimal_places` for the number of decimal places to display.

4. **Variable Declarations:**
   - `int magnitude;`: To store the magnitude (order of magnitude) of the number
   - `double fractional_part, temp;`: To store the fractional part of the number and a temporary value for calculations.
   - `char format_specifier[8];`: Array to hold the format specifier string for `printf`.
   - `char format_type[3] = {'l', 0, 0};`: Array to determine the format type (`'e'` for scientific notation or `'f'` for fixed-point notation).
   - `union ieee754_double *double_representation;`: Pointer to a union representing the IEEE 754 double-precision floating-point format.

5. **Calculating the Magnitude:**
   - `double_representation = (union ieee754_double*)&number;`: Casts the address of `number` to a pointer of type `union ieee754_double` to access its IEEE 754 components.
   - `magnitude = (double_representation->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;`: Calculates the magnitude of the number by adjusting the exponent from its IEEE 754 representation.

6. **Handling Zero:**
   - `if (number == 0) magnitude = 0;`: If the number is zero, explicitly set the magnitude to zero.

7. **Determining the Format Type:**
   - `if ((magnitude > max_digits_left - 1) || (magnitude < -max_zeros_right)) { ... }`: Checks if the magnitude exceeds the set thresholds for digits left of the decimal or consecutive zeros right of the decimal.
     - If true, sets `format_type[1] = 'e';` to use scientific notation.
     - Calculates `temp = number / pow(10, magnitude);` to scale the number.
     - Determines the fractional part `fractional_part = temp - floor(temp);`.
   - `else { ... }`: If the magnitude is within acceptable ranges:
     - Sets `format_type[1] = 'f';` to use fixed-point notation.
     - Calculates the fractional part `fractional_part = number - floor(number);`.

8. **Adjusting Decimal Places:**
   - `if (is_zero(fractional_part)) decimal_places = 0;`: If the fractional part is effectively zero, set `decimal_places` to zero to avoid displaying unnecessary decimal digits.

9. **Creating the Format Specifier:**
   - `if (width == 0) { ... }`: Checks if a specific width is not provided:
     - Uses `snprintf(format_specifier, 8, "%%.%d 
