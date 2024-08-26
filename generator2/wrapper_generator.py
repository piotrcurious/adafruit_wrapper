import os
import jinja2

class WrapperGenerator:
    def __init__(self, hardware_impl_dir, output_dir):
        self.hardware_impl_dir = hardware_impl_dir
        self.output_dir = output_dir
        self.template_dir = os.path.join(os.path.dirname(__file__), 'templates')
        self.jinja_env = jinja2.Environment(loader=jinja2.FileSystemLoader(self.template_dir))

    def generate_wrappers(self):
        for filename in os.listdir(self.hardware_impl_dir):
            if filename.endswith('.cpp'):
                hardware_impl_name = os.path.splitext(filename)[0]
                self.generate_wrapper(hardware_impl_name)

    def generate_wrapper(self, hardware_impl_name):
        # Render GFXWrapper.h
        template = self.jinja_env.get_template('GFXWrapper.h')
        output_path = os.path.join(self.output_dir, 'GFXWrapper.h')
        with open(output_path, 'w') as f:
            f.write(template.render(hardware_impl_name=hardware_impl_name))

        # Render GFXWrapper.cpp
        template = self.jinja_env.get_template('GFXWrapper.cpp')
        output_path = os.path.join(self.output_dir, 'GFXWrapper.cpp')
        with open(output_path, 'w') as f:
            f.write(template.render(hardware_impl_name=hardware_impl_name))

        # Render HardwareImplementation.cpp
        template = self.jinja_env.get_template('HardwareImplementation.cpp')
        output_path = os.path.join(self.output_dir, f'{hardware_impl_name}.cpp')
        with open(output_path, 'w') as f:
            f.write(template.render(hardware_impl_name=hardware_impl_name))

if __name__ == '__main__':
    hardware_impl_dir = 'path/to/hardware/implementations'
    output_dir = 'path/to/output'
    generator = WrapperGenerator(hardware_impl_dir, output_dir)
    generator.generate_wrappers()
