#include "streamforge/core/alert_event.hpp"
#include "streamforge/core/chat_message.hpp"
#include "streamforge/core/output_profile.hpp"
#include <cstdlib>
int main() {
  using namespace streamforge;
  ChatMessage chat{"m1", ChatPlatform::Twitch, "u1", "viewer", "hello", 1, false, false};
  if (!chat.is_valid()) return EXIT_FAILURE;
  chat.text.clear();
  if (chat.is_valid()) return EXIT_FAILURE;

  AlertEvent alert{AlertType::Follow, "twitch", "viewer", "New follower", 0, "", 2};
  if (!alert.is_valid()) return EXIT_FAILURE;
  alert.actor.clear();
  if (alert.is_valid()) return EXIT_FAILURE;

  OutputProfile output;
  output.target.display_name = "Twitch";
  output.ingest_url = "rtmps://live.example.invalid/app";
  output.secret_reference = "os-store://streamforge/twitch";
  if (!output.is_configured()) return EXIT_FAILURE;
  output.ingest_url = "https://example.invalid";
  if (output.is_configured()) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
