# StreamForge for OBS Studio 30.0.2

StreamForge is an independent OBS Studio extension project focused on creator workflows.

## Current development status

The portable C++ core currently contains:
- Stream destination state model
- Platform-neutral chat message contract
- Platform-neutral alert event contract
- Output profile validation for RTMP/RTMPS endpoints with an external secret reference
- CMake tests for the core models

These are foundation components, not complete platform integrations. There is not yet an installable OBS plugin, live Twitch/TikTok transport, OAuth login, unified live chat connection, alert renderer, or installer.

## Build

A starter CI workflow configures, compiles, and tests the portable core on Windows and Ubuntu. This is not an OBS SDK/plugin build. OBS Studio 30.0.2 SDK integration and a native dock remain required.

## Security

Never commit OAuth tokens, stream keys, client secrets, or personal credentials. The output profile stores only a secret reference, not a stream key. The eventual application should use the operating system credential store.

## Platform access

TikTok ingest and chat capabilities depend on account eligibility and official platform access. StreamForge will use authorized APIs and credentials only.

## License

License to be selected before public distribution.
