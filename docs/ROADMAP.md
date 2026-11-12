# Roadmap — prioritized scope

The active scope is limited to native OBS integration, multistream, platform login/OAuth, and the in-OBS user interface. Unified chat, alerts, and overlays are deferred.

## Native OBS Studio 30.0.2 integration
- [x] Portable C++ core and CMake test foundation
- [x] Initial OBS module entry point and OBS-managed dock widget source
- [x] Optional CMake target for libobs, obs-frontend-api, and Qt 6
- [ ] Pin and provision the exact OBS 30.0.2 build dependencies in CI
- [ ] Compile and load the module in OBS Studio 30.0.2 on Windows
- [ ] Verify dock lifecycle, reload, and clean unload

## Multistream
- [ ] Multi-output manager using supported OBS output/encoder APIs
- [ ] Independent Twitch and TikTok output configuration
- [ ] Start/stop, per-destination status, retries, and error reporting
- [ ] Validate simultaneous outputs without destabilizing OBS

## Login and OAuth
- [ ] Twitch authorization using official OAuth flow
- [ ] TikTok authorization only where official API/app permissions allow it
- [ ] Secure token storage using the operating-system credential store
- [ ] Token refresh, revocation, and disconnect flows

## In-OBS interface
- [x] Initial native dock source
- [ ] Account connection and status views
- [ ] Destination setup and stream controls
- [ ] Visual polish, accessibility, and localization
- [ ] Persist user settings safely

## Current limitations

The dock is a source-level foundation only. Its connection and multistream controls are intentionally disabled until their backends exist. No successful OBS 30.0.2 plugin build or runtime test has yet been recorded.

TikTok ingest and API features depend on account eligibility and platform-issued access. The application will use authorized APIs only and will not fabricate or bypass credentials.
