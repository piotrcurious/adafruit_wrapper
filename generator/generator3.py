import re
import json

def parse_header(header_file):
    """Parse the header file to extract the class name and method signatures."""
    with open(header_file, 'r') as file:
        content = file.read()

    # Find the class name that inherits from Adafruit_GFX
    class_match = re.search(r'class\s+(\w+)\s*:\s*public\s+Adafruit_GFX', content)
    if not class_match:
        raise ValueError("No class inheriting from Adafruit_GFX found in header file.")

    class_name = class_match.group(1)

    # Extract method signatures (excluding constructors, destructors, and private/protected methods)
    methods = re.findall(r'(?:(public|private|protected):)?\s*(\w[\w\s\*&]*?)\s+(\w+)\s*(.*?)\s*;', content, re.DOTALL)
    public_methods = [(ret_type.strip(), name, args.strip()) for access, ret_type, name, args in methods if access != 'private' and access != 'protected']

    return class_name, public_methods

def generate_header(class_name, methods, config):
    """Generate the header file content for the wrapper class."""
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

    # Add method signatures to the header file
    for return_type, method_name, arguments in methods:
        wrapper_code += f"    {return_type} {method_name}({arguments});\n"

    wrapper_code += """
};

#endif // DISPLAY_WRAPPER_H
"""
    return wrapper_code

def generate_cpp(class_name, methods, config):
    """Generate the cpp file content for the wrapper class."""
    cpp_code = f"""#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper() : Adafruit_GFX({config['width']}, {config['height']}), display() {{
}}

void DisplayWrapper::begin() {{
    display.begin();
}}

"""

    # Implement the methods in the cpp file
    for return_type, method_name, arguments in methods:
        args_list = arguments.split(', ') if arguments else []
        params = ', '.join([arg.split()[-1] for arg in args_list])

        if return_type == "void":
            cpp_code += f"""void DisplayWrapper::{method_name}({arguments}) {{
    display.{method_name}({params});
}}

"""
        else:
            cpp_code += f"""{return_type} DisplayWrapper::{method_name}({arguments}) {{
    return display.{method_name}({params});
}}

"""

    return cpp_code

def main():
    """Main function to generate the wrapper files."""
    config_file = 'config.json'
    with open(config_file, 'r') as file:
        config = json.load(file)

    # Parse header to get class name and methods
    class_name, methods = parse_header(config['header_file'])

    # Generate wrapper header file
    header_code = generate_header(class_name, methods, config)
    with open('DisplayWrapper.h', 'w') as file:
        file.write(header_code)

    # Generate wrapper cpp file
    cpp_code = generate_cpp(class_name, methods, config)
    with open('DisplayWrapper.cpp', 'w') as file:
        file.write(cpp_code)

    print("Wrapper generated: DisplayWrapper.h and DisplayWrapper.cpp")

if __name__ == "__main__":
    main()
