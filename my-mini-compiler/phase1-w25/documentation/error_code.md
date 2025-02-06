## Error Code Documentation 

### Overview 
This document provides a reference for error codes encountered during lexical analysis. Each error code corresponds to a specific issue that may arise when processing tokens.

### Error Codes

| Error Code | Description | Cause | Example | Solution |
|------------|-------------|-------|---------|------------|
| **ERROR_INVALID_CHAR** | An unrecognized character was encountered in the input. | The lexer encountered a character that is not part of the valid syntax. | ``` int $var = 10; ``` The `$` character is invalid in this context. | Ensure all characters in the source code belong to the supported syntax. |
| **ERROR_INVALID_NUMBER** | A number is incorrectly formatted. | Numbers must contain only digits and valid decimal points. | ``` int num = 123abc; ``` `123abc` is not a valid number. | Ensure numbers are formatted correctly and do not contain invalid characters. |
| **ERROR_CONSECUTIVE_OPERATORS** | Two consecutive operators that are not a valid multi-character operator were found. | The lexer detected an invalid sequence of operators. | ``` int x = 5 ** 2; ``` `**` is not a valid operator. | Use only supported operators such as `+`, `-`, `*`, `/`, `==`, `!=`, `<=`, `>=`. |
| **ERROR_UNKNOWN_ESCAPE_SEQUENCE** | An invalid escape sequence was found within a string. | The lexer encountered an unrecognized escape sequence. | ``` string text = "Hello\qWorld"; ``` `\q` is not a valid escape sequence. | Use only valid escape sequences such as `\n`, `\t`, `\"`, `\\`. |
| **ERROR_UNTERMINATED_STRING** | A string was opened but never properly closed. | The lexer reached the end of the input without encountering a closing quotation mark. | ``` string message = "Hello World; ``` The closing `"` is missing. | Ensure all strings have matching opening and closing quotation marks. |
