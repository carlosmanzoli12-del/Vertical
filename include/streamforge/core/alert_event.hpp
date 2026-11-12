#pragma once
#include <cstdint>
#include <string>
namespace streamforge {
enum class AlertType { Follow, Subscription, Donation, Gift, Raid, Like, Custom };
struct AlertEvent {
  AlertType type{AlertType::Custom};
  std::string source;
  std::string actor;
  std::string message;
  std::uint64_t amount_minor{0};
  std::string currency;
  std::uint64_t timestamp_ms{0};
  [[nodiscard]] bool is_valid() const noexcept;
};
} // namespace streamforge
