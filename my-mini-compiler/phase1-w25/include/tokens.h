#ifndef TOKENS_H
#define TOKENS_H

/*--------------------------------------------------------------------
 * TOKEN TYPES
 *--------------------------------------------------------------------*/
typedef enum {
    TOKEN_EOF,            // End Of File
    TOKEN_NUMBER,         // e.g., "123", "3.14" (if you add floating point support)
    TOKEN_OPERATOR,       // e.g., "+", "-", "*", "/", "++", "--", "=="
    TOKEN_KEYWORD,        // e.g., "if", "repeat", "until"
    TOKEN_IDENTIFIER,     // e.g., variable names, function names
    TOKEN_STRING_LITERAL, // e.g., "Hello World"
    TOKEN_DELIMITER,      // e.g., ";", "(", ")", "{", "}"
    TOKEN_ERROR           // Generic error token
} TokenType;

/*--------------------------------------------------------------------
 * ERROR TYPES
 *
 *--------------------------------------------------------------------*/
typedef enum {
    ERROR_NONE,
    ERROR_INVALID_CHAR,            // e.g., "x@" if '@' isn't allowed
    ERROR_INVALID_NUMBER,          // e.g., "123abc"
    ERROR_CONSECUTIVE_OPERATORS,   // e.g., "+++" if not allowed
    ERROR_UNTERMINATED_STRING,     // e.g., "Hello
    ERROR_UNKNOWN_ESCAPE_SEQUENCE  // e.g., "\q"
} ErrorType;

/*--------------------------------------------------------------------
 * TOKEN STRUCTURE
 *
 *--------------------------------------------------------------------*/
typedef struct {
    TokenType type;          // The type of token
    char lexeme[256];        // The text that makes up this token
    int line;                // Line number for debugging
    ErrorType error;         // Error code if this token is invalid
} Token;

#endif /* TOKENS_H */
