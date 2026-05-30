# RXFG-RXSR UI Architecture

## Design Goals
- Frosted glass aesthetic
- High performance
- Dark-first theme
- Real-time monitoring
- Minimal navigation depth

## Main Views
- Dashboard
- RXSR
- RXFG
- Monitoring
- Profiles
- Diagnostics
- Settings

## Dashboard Widgets
- Native FPS
- Generated FPS
- Frame Latency
- CPU Usage
- GPU Usage
- VRAM Usage
- Active Game

## Navigation
Left navigation rail with icon-based sections.

## Rendering
Recommended stack:
- Dear ImGui
- DirectX 11 backend initially
- Custom blur and acrylic effects later
