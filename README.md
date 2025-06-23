# conf - config manager for C++

*conf* is one-header module (actually library) for C++ to use your config file in projects. See `Usage` for details 

## Build
1. Clone or copy the repository as domain:
```bash
git clone 'https://github.com/johann-gorban/conf'
```
2. In the CMakeLists of domain that uses the module write:
```
add_subdirectory(conf)
```


## Usage

Firstly, you need to `init` the conf file. There are two ways you can provide the config file
```
class Config {
    void init(std::ifstream &config_file);

    void init(const std::string &config_name);
}
```

That's all! You can use it:
```
// After the conf object of Config created and init called
int max_connections = conf.get("MAX_CONN").to_int();

bool is_default = conf.get("DEFAULT").to_bool();
```

## Syntax

```ebnf
<config>     ::= <assignment_list>
<assignment_list> ::= 
                  | <assignment> <assignment_list>

<assignment> ::= <lvalue> "=" <rvalue> <assignment_end>

<lvalue>     ::= <identifier>
<identifier> ::= <letter> 
               | <letter> <identifier_rest>
<identifier_rest> ::= 
                  | <alphanumeric> <identifier_rest>
<alphanumeric> ::= <letter> | <digit>

<rvalue>     ::= <number> 
               | <string> 
               | <array>

<number>     ::= <integer> 
               | <float>
<integer>    ::= <digit> 
               | "-" <digit> 
               | <digit> <integer> 
               | "-" <digit> <integer>
<float>      ::= <integer> "." 
               | <integer> "." <digit_sequence>
               | "." <digit_sequence>
               | "-" <integer> "."
               | "-" <integer> "." <digit_sequence>
               | "-" "." <digit_sequence>
<digit_sequence> ::= <digit> 
                   | <digit> <digit_sequence>

<string>     ::= "\"" <string_content> "\""
<string_content> ::= any char 
                  | any char <string_content>

<array>      ::= "[" <array_items> "]" 
               | "[" "]"
<array_items> ::= <rvalue> 
                | <rvalue> "," <array_items>

<assignment_end> ::= <whitespace> <assignment_end>
                   | <newline> <whitespace>
                   | <newline>
                   | <whitespace> <newline> <assignment_end>

<letter>     ::= "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" 
               | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" 
               | "u" | "v" | "w" | "x" | "y" | "z" 
               | "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" 
               | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" 
               | "U" | "V" | "W" | "X" | "Y" | "Z"

<digit>      ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

<whitespace> ::= " " | "\t"
<newline>    ::= "\n"
```

### Key Specifications
1. **Identifiers (lvalue)**:
   - Start with letter (`A-Za-z`)
   - Contain letters/digits (`0-9`)
   - Case-sensitive  
   Examples: `timeout`, `MAX_SIZE`, `color2`

2. **Values (rvalue)**:
   - **Numbers**: 
     - Integers: `42`, `-7`
     - Floats: `3.14`, `.5`, `-0.01`
   - **Strings**: 
     - Enclosed in `"`
     - No escape characters  
     Examples: `"text"`, `""`
   - **Arrays**:
     - Mixed types allowed
     - Arbitrary nesting  
     Examples: `[1,"a"]`, `[[8.1],[]]`, `[]`

3. **Whitespace Rules**:
   - Allowed around operators (`=`, `,`, `[`, `]`)
   - Required between assignments
   - Forbidden within tokens

### Valid Example
```ini
title = "Annual Report"
dimensions = [1920, 1080.5]
palette = ["red", "green", [0,255,0]]
transform = [
  [1.0, 0.0, -0.5],
  [0.0, 1.0, 100],
  [0, 0, 1]
]
```

### Invalid Patterns
```ini
user name = "Alex"  X Space in identifier
5stars = 10         X Digit-first identifier
items=[1 2,3]       X Missing comma
port=8080log=true   X Missing separator
```
