from setuptools import find_packages
from setuptools import setup

setup(
    name='swd_ros2_controllers',
    version='2.1.0',
    packages=find_packages(
        include=('swd_ros2_controllers', 'swd_ros2_controllers.*')),
)
