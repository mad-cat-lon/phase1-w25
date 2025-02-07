# Grammar
**N: Non-terminals**
```
N = { 
    Program, Statement, Declaration, VariableDeclaration, Assignment, Expression, BooleanExpression, 
    RelationalExpression, ExpressionList, Term, Factor, Keyword, StringLiteral, RepeatUntil, ForLoop,  
} 
```
<br>

**T: Terminals**
```
T = { 
    id, number,
    +, -, *, /, %, &,
    ==, <, >, <=, >=, !, ||, &&,
    ,, (, ), {, }, [, ], ;,
    =, 
    if, repeat, until, else, for,
    function, return, void, break,
    int, float, char,
    "string",
    ERROR
}
```
<br>

**P: Production Rules**
```
Program -> Statement | Statement Program

Statement -> Expression ; | Declaration ; | Assignment ; | Keyword Statement | RepeatUntil | ForLoop | { Program }

Declaration -> VariableDeclaration | const VariableDeclaration

VariableDeclaration -> Keyword id (= Expression)? | Keyword id [ number ] (= { ExpressionList })?

Assignment -> id = Expression

Expression -> Expression + Term | Expression - Term | Term

BooleanExpression -> BooleanExpression && RelationalExpression | BooleanExpression || RelationalExpression | RelationalExpression

RelationalExpression -> Expression == Expression | Expression != Expression | Expression < Expressions | Expression > Expression | Expression <= Expression | Expression >= Expression | Expression

ExpressionList -> Expression | Expression , ExpressionList

Term -> Term * Factor | Term / Factor | Term % Factor | Factor

Factor -> id | number | StringLiteral | ( Expression )

Keyword -> if | repeat | until | else | for | function | return | break | void | int | float | char | string

StringLiteral -> "string"

RepeatUntilStatement -> repeat { Program } until ( BooleanExpression ) ;

ForLoopStatement -> for ( VariableDeclaration ; BooleanExpression ; Expression ) { Program }
```
<br>

**S: Start Symbol**
```
S = Program
```