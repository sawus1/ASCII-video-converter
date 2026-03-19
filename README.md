# ASCII Video Converter (C++ + OpenCV)

Convert videos into animated ASCII art directly in your terminal or export them as executable `.sh` scripts.

---

## Features

* Convert MP4 videos to ASCII
* Real-time terminal rendering
* Export videos as `.sh` scripts
* Custom ASCII charset
* Resolution scaling for performance
* Optimized rendering (buffered output)

---

## Tech Stack

* C++17
* OpenCV
* CMake

---

## Build

```bash
git clone https://github.com/yourusername/ascii-video-converter.git
cd ascii-video-converter

mkdir build && cd build
cmake ..
make
```

---

## Usage

```bash
./ascii-video input.mp4
```

### Optional arguments

```bash
./ascii-video input.mp4 --display-width 120 --output-filename output.sh
```

---

## Export to .sh

```bash
./ascii-video input.mp4 -o video.sh
chmod +x video.sh
./video.sh
```

---

## How it works

1. Extract frames from video
2. Convert to grayscale
3. Resize for ASCII
4. Map pixels → ASCII characters
5. Render or export

---

## Project Structure

```
src/
    frame_processor.cpp
    ascii_converter.cpp
    renderer.cpp
    video_exporter.cpp

include/
    *.hpp
```

---

## Future Improvements

* [ ] Streaming pipeline (no full video in memory)
* [ ] Multithreading
* [ ] ANSI color support
* [ ] GPU acceleration

---

## Example

```
@@@@@@%%%%%%%#######
@@@@@@%%%%%%%#######
```

---

## 📄 License

MIT
