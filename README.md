# StreamForge for OBS Studio 30.0.2

StreamForge is an independent OBS Studio extension project focused on creator workflows.

## Project status

This repository is being initialized. Features are developed incrementally and are not considered complete until they are built and tested against OBS Studio 30.0.2.

Planned modules:
- OBS dock and controls
- Twitch and TikTok multistream (requires authorized ingest credentials for each platform)
- Unified chat
- Platform account integration
- Browser-based alerts

## Build

The initial Windows CI workflow is being added. See `.github/workflows` after the first workflow commit.

## Security

Never commit OAuth tokens, stream keys, client secrets, or personal credentials. Use GitHub Actions secrets for CI and the operating system credential store for local account tokens.

## License

License to be selected before public distribution.
