# Roadmap

## Foundation
- [x] Repository and CMake skeleton
- [x] Cross-platform CI smoke build and unit test
- [ ] OBS Studio 30.0.2 SDK integration and native dock

## Streaming
- [ ] Multi-output encoder/session manager
- [ ] Twitch output adapter
- [ ] TikTok output adapter
- [ ] Per-platform ingest configuration and health status

## Community
- [ ] Unified chat abstraction
- [ ] Twitch chat adapter
- [ ] TikTok chat adapter (subject to supported API/access)
- [ ] Alert event bus and browser overlay

## Accounts and security
- [ ] OAuth flows using official platform endpoints
- [ ] Secure token storage; never store stream keys in source control

TikTok ingest credentials and feature availability depend on account eligibility and platform-issued access. The application will not bypass platform restrictions or fabricate credentials.
