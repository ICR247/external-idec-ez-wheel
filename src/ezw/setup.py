from setuptools import find_packages, setup

package_name = 'ezw'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/bringup.launch.py']), # why do we have to add this???
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='icr247',
    maintainer_email='icr247@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "tcp_can_client = ezw.test:main",
            "tcp_can_diff_client = ezw.diff_drive:main",
            "object_detector = ezw.object_detector:main",
        ],
    },
)
