from distutils.core import setup
import sys

if sys.version_info < (3,0):
  sys.exit('Sorry, Python < 3.0 is not supported')

setup(
    name='myproject',
    version='0.0.1',
    description='myproject bindings for python',
    author='Dirk Adler',
    author_email='adlerdirk@gmx.de',
    url='https://github.com/EagleDad/cmake-playground.git',
    
    include_package_data=True,
    
    packages=['myproject'],
    package_dir={'myproject': ''},
    package_data={'myproject': ['*.pyd', '*.dll']},
   
)