#pragma once
#include <cstdint>
#include <string>
namespace streamforge {
enum class ChatPlatform { Twitch, TikTok, YouTube, Unknown };
struct ChatMessage {
  std::string id;
  ChatPlatform platform{ChatPlatform::Unknown};
  std::string user_id;
  std::string user_name;
  std::string text;
  std::uint64_t timestamp_ms{0};
  bool moderator{false};
  bool subscriber{false};
  [[nodiscard]] bool is_valid() const noexcept;
};
} // namespace streamforge
