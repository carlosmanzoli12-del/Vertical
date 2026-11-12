#include "streamforge/core/output_profile.hpp"
namespace streamforge {
bool OutputProfile::is_configured() const noexcept {
  const bool supported_scheme = ingest_url.rfind("rtmp://", 0) == 0 ||
                                ingest_url.rfind("rtmps://", 0) == 0;
  return supported_scheme && ingest_url.size() > 7 &&
         !secret_reference.empty() && !target.display_name.empty();
}
} // namespace streamforge
