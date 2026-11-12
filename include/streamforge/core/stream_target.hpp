#pragma once
#include <string>
namespace streamforge {
enum class Platform { Twitch, TikTok, YouTube, Custom };
enum class TargetState { Disconnected, Connecting, Live, Error };
struct StreamTarget {
  Platform platform{Platform::Custom};
  TargetState state{TargetState::Disconnected};
  std::string display_name;
  [[nodiscard]] bool can_connect() const noexcept;
};
} // namespace streamforge
