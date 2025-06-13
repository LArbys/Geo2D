# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

### Environment Setup
```bash
# For containers
source config/setup_container.sh

# For standard environments
source config/setup.sh
```

### Build Process
```bash
cd $GEO2D_BASEDIR
mkdir -p build && cd build
cmake .. -DUSE_PYTHON3=ON
make
```

### Alternative Build (Legacy)
```bash
cd $GEO2D_BASEDIR
make
```

## Testing

This project uses manual testing with individual Python scripts and Jupyter notebooks:

### Python Tests
```bash
cd $GEO2D_BASEDIR/Geo2D/PyUtil/test
python test.py
python test_mat.py
```

### Jupyter Notebook Tests
```bash
jupyter notebook Geo2D/Core/test/test_AABox.ipynb
# Other notebook tests: test_Circle.ipynb, test_OBox.ipynb, etc.
```

## Architecture

Geo2D is a C++ library for 2D geometry operations with Python bindings through ROOT's PyROOT.

### Core Components

- **Geo2D/Core/**: Fundamental geometry classes (Vector, Line, Circle, BoundingBox, etc.)
- **Geo2D/Algorithm/**: Geometric algorithms (ConvexHull, etc.)
- **Geo2D/PyUtil/**: Python bindings and drawing utilities

### Key Dependencies

- **ROOT**: CERN's data analysis framework (required)
- **OpenCV**: Computer vision library (required)
- **Python**: 2.7 or 3.x with NumPy

### Build System

- Recently migrated from Makefiles to CMake
- Automatically detects C++ standard based on ROOT version (C++11/14/17)
- Supports both Python 2 and Python 3
- CMAKE_INSTALL_PREFIX defaults to `${CMAKE_BINARY_DIR}/installed`

### Environment Variables

After setup, these variables are available:
- `GEO2D_BASEDIR`: Base directory
- `GEO2D_LIBDIR`: Library directory (build/installed/lib)
- `GEO2D_INCDIR`: Include directory (build/installed/include)
- `GEO2D_PYTHON_VERSION`: Python version (2 or 3)

### Template Classes

Many core classes use template implementations with `.imp.h` files for generic functionality.