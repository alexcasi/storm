/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_BASICFILESINK_HPP
#define STORM_SINKS_BASICFILESINK_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/basic_log_sink.hpp"

#include <asioext/scoped_file_handle.hpp>

#include <vstl/string.hpp>
#include <vstl/string_view.hpp>

#include <boost/system/error_code.hpp>

STORM_NS_BEGIN

class basic_file_sink : public basic_log_sink
{
public:
  STORM_DECL basic_file_sink();
  STORM_DECL basic_file_sink(const vstd::string_view& filename);
  STORM_DECL basic_file_sink(const vstd::string_view& filename,
                             boost::system::error_code& ec);

  STORM_DECL void open(const vstd::string_view& filename);
  STORM_DECL void open(const vstd::string_view& filename,
                       boost::system::error_code& ec);
  STORM_DECL void close();
  STORM_DECL bool is_open() const;

  STORM_DECL const vstd::string& filename() const;

  STORM_DECL void write_record(const vstd::string_view& record);

private:
  vstd::string filename_;
  asioext::scoped_file_handle file_;
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/sinks/impl/basic_file_sink.cpp"
#endif

#endif
