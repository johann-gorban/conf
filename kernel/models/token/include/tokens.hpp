#pragma once

#include "token.hpp"
#include "bool.hpp"
#include "float.hpp"
#include "integer.hpp"
#include "string.hpp"

#include <memory>

using token_ptr = std::shared_ptr<Token>;