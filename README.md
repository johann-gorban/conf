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