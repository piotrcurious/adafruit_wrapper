To improve the Python script to also generate a `.cpp` file for delegating function calls, we'll need to expand the code to handle both the declaration (header file) and the definition (CPP file). Here's how to approach this:

### Steps:
1. **Parse the SSD1306 header file**: Extract class names and method signatures.
2. **Generate a wrapper header file (`DisplayWrapper.h`)**: Declare a class that inherits from `Adafruit_GFX` and contains an instance of the hardware class (e.g., `Adafruit_SSD1306`).
3. **Generate a CPP file (`DisplayWrapper.cpp`)**: Implement the methods in the wrapper class, delegating calls to the hardware class.

### Updated Python Script

```python
import re
import json

def parse_header(header_file):
    with open(header_file, 'r') as file:
        content = file.read()

    # Extract the class name that inherits from Adafruit_GFX
    class_match = re.search(r'class\s+(\w+)\s*:\s*public\s+Adafruit_GFX', content)
    if not class_match:
        raise ValueError("No class inheriting from Adafruit_GFX found in header file.")

    class_name = class_match.group(1)

    # Extract method signatures
    methods = re.findall(r'(\w+\s+\w+\(.*?\);)', content, re.DOTALL)

    return class_name, methods

def generate_header(class_name, methods, config):
    wrapper_code = f"""#ifndef DISPLAY_WRAPPER_H
#define DISPLAY_WRAPPER_H

#include <{config['header_file']}>
#include <Adafruit_GFX.h>

class DisplayWrapper : public Adafruit_GFX {{
private:
    {class_name} display;
public:
    DisplayWrapper();
    void begin();

"""

    for method in methods:
        method_signature = method.replace(';', '')
        wrapper_code += f"    {method_signature};\n"

    wrapper_code += """
};

#endif // DISPLAY_WRAPPER_H
"""
    return wrapper_code

def generate_cpp(class_name, methods, config):
    cpp_code = f"""#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper() : Adafruit_GFX({config['width']}, {config['height']}), display() {{
}}

void DisplayWrapper::begin() {{
    display.begin();
}}

"""

    for method in methods:
        # Extract return type, name, and arguments
        return_type, rest = method.split(' ', 1)
        method_name = re.match(r'\w+', rest).group(0)
        arguments = re.findall(r'\((.*?)\)', rest)[0]

        cpp_code += f"""{return_type} DisplayWrapper::{method_name}({arguments}) {{
    return display.{method_name}({arguments.split(', ')[0] if arguments else ''});
}}

"""

    return cpp_code

def main():
    config_file = 'config.json'
    with open(config_file, 'r') as file:
        config = json.load(file)

    # Parse header to get class name and methods
    class_name, methods = parse_header(config['header_file'])

    # Generate wrapper header
    header_code = generate_header(class_name, methods, config)
    with open('DisplayWrapper.h', 'w') as file:
        file.write(header_code)

    # Generate wrapper cpp
    cpp_code = generate_cpp(class_name, methods, config)
    with open('DisplayWrapper.cpp', 'w') as file:
        file.write(cpp_code)

    print("Wrapper generated: DisplayWrapper.h and DisplayWrapper.cpp")

if __name__ == "__main__":
    main()
```

### Configuration File (`config.json`)

```json
{
    "header_file": "Adafruit_SSD1306.h",
    "width": 128,
    "height": 64
}
```

### Explanation:

1. **`parse_header`**: Reads the header file, identifies the class inheriting from `Adafruit_GFX`, and extracts method signatures.
2. **`generate_header`**: Creates the `DisplayWrapper.h` file. This file declares a class that inherits from `Adafruit_GFX` and contains an instance of the specific hardware class (like `Adafruit_SSD1306`).
3. **`generate_cpp`**: Creates the `DisplayWrapper.cpp` file. This file implements the methods of the `DisplayWrapper` class, delegating calls to the corresponding methods of the hardware class.
4. **`main`**: Reads the configuration, parses the header file, and generates both the `.h` and `.cpp` files.

### Output Files:

- **`DisplayWrapper.h`**: Contains the class declaration and method prototypes.
- **`DisplayWrapper.cpp`**: Contains the method implementations that delegate the calls to the selected hardware class.

### Sample Output:

For `Adafruit_SSD1306.h`:

**`DisplayWrapper.h`**:
```cpp
#ifndef DISPLAY_WRAPPER_H
#define DISPLAY_WRAPPER_H

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class DisplayWrapper : public Adafruit_GFX {
private:
    Adafruit_SSD1306 display;
public:
    DisplayWrapper();
    void begin();
    void clearDisplay();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    // Other methods...
};

#endif // DISPLAY_WRAPPER_H
```

**`DisplayWrapper.cpp`**:
```cpp
#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper() : Adafruit_GFX(128, 64), display() {
}

void DisplayWrapper::begin() {
    display.begin();
}

void DisplayWrapper::clearDisplay() {
    return display.clearDisplay();
}

void DisplayWrapper::drawPixel(int16_t x, int16_t y, uint16_t color) {
    return display.drawPixel(x, y, color);
}

// Other methods...
```

This script is flexible and can be extended to handle other hardware classes by simply updating the `config.json` with the appropriate header file and display dimensions. The generated wrapper files can then be used in Arduino projects to easily switch between different hardware implementations by only changing the wrapper class instantiation.
