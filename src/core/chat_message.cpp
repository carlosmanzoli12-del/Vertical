#include "streamforge/core/chat_message.hpp"
namespace streamforge {
bool ChatMessage::is_valid() const noexcept {
  return !id.empty() && !user_name.empty() && !text.empty();
}
} // namespace streamforge
