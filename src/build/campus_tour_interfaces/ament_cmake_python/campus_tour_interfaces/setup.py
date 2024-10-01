from setuptools import find_packages
from setuptools import setup

setup(
    name='campus_tour_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('campus_tour_interfaces', 'campus_tour_interfaces.*')),
)
