## Lexer Design Decisions
**How did identifiers and keywords were distinguished**
1. Both identifiers and keywords were intially categorized using the same method.
    If a token starts with a letter (`isalpha(c)`) or an underscore(`'_'`), it is considered either an identifier or a keyword.
2. The lexer then reads the subsequent characters or underscores extracting the full lexeme.
3. This lexeme is then crossreferenced with the predefined list of keywords (`is_keyword(token.lexeme`)
4. Depending on the result it is set as a `TOKEN_KEYWORD` or `TOKEN_IDENTIFIER`

**What is a valid identifier**
- A valid intifier was recognized using these rules
    - It must start with a letter (a-z, A-Z) or an underscore (_).
    - The rest can contain any alphanumerical characeter or unserscores
    - It cannot be a reserved keyword

**How are multi-character operators handled**
1. If the first character of a toke is recognized as an operator (`is_operator_char(c)`), the lexer reads it as an operator
2. It then checks for possible second characters to form a multi-character operator:
    ex: `==`, `!=`, `<=`, `>=`.
3. If the second character is found to have matched it is appended to token lexeme.
4. Other consecutive operators (`++`, `--`, `**`) are flagged as `ERROR_CONSECUTIVE_OPERATORS` to prevent invalid sequences.

**What helpful error messages have been included**
- `ERROR_INVALID_CHAR`: When an unrecognized character is encountered (e.g., `$ in i $= 2`).
- `ERROR_INVALID_NUMBER`: When a number is incorrectly formatted (e.g., `123abc`).
- `ERROR_CONSECUTIVE_OPERATORS`: When two consecutive operators that are not valid together appear (e.g., `++`, `**`).
- `ERROR_UNKNOWN_ESCAPE_SEQUENCE`: When an invalid escape sequence is found in a string (e.g., `"Hello\qWorld"`).
- `ERROR_UNTERMINATED_STRING`: When a string is opened with " but not closed before the end of the input.

**Additional Changes**
- `is_keyword(str)` was expanded to include:
  - Control flow keywords (e.g., `if`, `while`, `repeat`). 
  - Function & Scope keywords (e.g.,`function`, `return`, `void`).
  - Variable/data type keywords (e.g., `int`).
- Returning 1 if any of the keywords find a match.