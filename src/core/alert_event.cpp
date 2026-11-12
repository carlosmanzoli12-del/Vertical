#include "streamforge/core/alert_event.hpp"
namespace streamforge {
bool AlertEvent::is_valid() const noexcept {
  return !source.empty() && !actor.empty() && !message.empty();
}
} // namespace streamforge
