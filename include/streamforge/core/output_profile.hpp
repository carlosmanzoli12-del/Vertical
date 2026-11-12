#pragma once
#include "streamforge/core/stream_target.hpp"
#include <string>
namespace streamforge {
// Credentials are referenced by an OS-backed secret store; never store stream keys here.
struct OutputProfile {
  StreamTarget target;
  std::string ingest_url;
  std::string secret_reference;
  [[nodiscard]] bool is_configured() const noexcept;
};
} // namespace streamforge
