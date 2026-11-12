#include "streamforge/core/stream_target.hpp"
namespace streamforge {
bool StreamTarget::can_connect() const noexcept {
  return state == TargetState::Disconnected || state == TargetState::Error;
}
} // namespace streamforge
