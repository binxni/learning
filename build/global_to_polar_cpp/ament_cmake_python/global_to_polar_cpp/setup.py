from setuptools import find_packages
from setuptools import setup

setup(
    name='global_to_polar_cpp',
    version='0.0.0',
    packages=find_packages(
        include=('global_to_polar_cpp', 'global_to_polar_cpp.*')),
)
