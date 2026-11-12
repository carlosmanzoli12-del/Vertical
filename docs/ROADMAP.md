# Roadmap

## Foundation
- [x] Repository and CMake skeleton
- [x] Cross-platform CI smoke build and unit test
- [x] Normalized chat, alert, and output-profile domain models
- [ ] OBS Studio 30.0.2 SDK integration and native dock

## Streaming
- [ ] Multi-output encoder/session manager
- [ ] Twitch output adapter
- [ ] TikTok output adapter
- [ ] Per-platform ingest configuration and health status

## Community
- [x] Unified chat message data contract
- [ ] Twitch chat adapter
- [ ] TikTok chat adapter (subject to supported API/access)
- [x] Normalized alert event data contract
- [ ] Alert event bus and browser overlay

## Accounts and security
- [ ] OAuth flows using official platform endpoints
- [ ] Secure token storage; never store stream keys in source control

The current chat and alert models are platform-neutral data contracts only; they do not connect to platform APIs yet. Output profiles validate RTMP/RTMPS endpoints and reference credentials stored elsewhere; they do not transmit video yet.

TikTok ingest credentials and feature availability depend on account eligibility and platform-issued access. The application will not bypass platform restrictions or fabricate credentials.
