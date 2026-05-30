# Technical Debt Rules

1. Every subsystem must compile before the next subsystem is added.
2. Avoid hardcoded paths.
3. Platform-specific code belongs only in platform/windows.
4. No RXFG code inside RXSR modules.
5. No RXSR code inside RXFG modules.
6. Shared functionality belongs in core.
7. Every public interface must be documented.
8. Prefer modular services over global state.
