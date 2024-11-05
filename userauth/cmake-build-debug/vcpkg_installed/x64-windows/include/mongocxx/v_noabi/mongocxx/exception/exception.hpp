// Copyright 2009-present MongoDB, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <system_error>

#include <mongocxx/exception/exception-fwd.hpp>

#include <bsoncxx/config/prelude.hpp>

#include <mongocxx/config/prelude.hpp>

namespace mongocxx {
namespace v_noabi {

BSONCXX_PUSH_WARNINGS();
BSONCXX_DISABLE_WARNING(MSVC(4251));
BSONCXX_DISABLE_WARNING(MSVC(4275));

///
/// A class to be used as the base class for all mongocxx exceptions.
///
class exception : public std::system_error {
   public:
    ~exception() override;

    exception(exception&&) = default;
    exception& operator=(exception&&) = default;
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;

    using system_error::system_error;
};

BSONCXX_POP_WARNINGS();

}  // namespace v_noabi
}  // namespace mongocxx

#include <bsoncxx/config/postlude.hpp>

#include <mongocxx/config/postlude.hpp>

///
/// @file
/// Provides @ref mongocxx::v_noabi::exception.
///