from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'ezw'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.*')), # add so that launch files are installed
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='icr247',
    maintainer_email='icr247@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    # tests_require=['pytest'],    # Anna commented out because not needed
    entry_points={
        'console_scripts': [
            "follow_ball = ezw.follow_ball:main",
        ],
    },
)
