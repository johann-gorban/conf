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

Configuration files follow these formal grammar rules:

```ebnf
<config>     = { <assignment> }
<assignment> = <lvalue> "=" <rvalue> <assignment_end>
<lvalue>     = ? /[a-zA-Z][a-zA-Z0-9]*/ ?
<rvalue>     = <number> | <string> | <array>
<number>     = <integer> | <float>
<integer>    = ? /-?[0-9]+/ ?
<float>      = ? /-?([0-9]+\.[0-9]*|\.[0-9]+)/ ?
<string>     = ? /"[^"]*"/ ?
<array>      = "[" [ <rvalue> { "," <rvalue> } ] "]"
<assignment_end> = ? /(\s*\n\s*)+/ ?
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
path="C:\files"     X Backslash not allowed
items=[1 2,3]       X Missing comma
port=8080log=true   X Missing separator
```
