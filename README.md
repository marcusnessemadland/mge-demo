[mge-demo](https://github.com/marcusnessemadland/mge-demo) - Demo of Modern Graphics Engine
============================================================================

<p align="center">
    <a href="#what-is-it">What is it?</a> -
    <a href="#building">Building</a> -
    <a href="#license-apache-2">License</a>
</p>

[![License](https://img.shields.io/github/license/marcusnessemadland/mge)](https://github.com/marcusnessemadland/mge/blob/main/LICENSE)

[What is it?](https://github.com/marcusnessemadland/mge)
-------------------------------------------------------------

This is a simple demo of [mge](https://github.com/marcusnessemadland/mge), showcasing rendering of [NVIDIA](https://developer.nvidia.com/orca/) scenes [Bistro](https://developer.nvidia.com/orca/amazon-lumberyard-bistro) and [Sun Temple](https://developer.nvidia.com/ue4-sun-temple).

[Building](https://github.com/marcusnessemadland/mge)
-------------------------------------------------------------

Submodules are used to include any essential dependencies.

When acquiring the code make sure to clone the repo with submodules included:

```bash
git clone --recurse-submodules https://github.com/marcusnessemadland/mge-demo.git
```

If you have already cloned this repo without submodules, then use:

```bash
git submodule update --init --recursive
```

Then CMake is used for building IDE project solutions:

```bash
cd mge-demo
mkdir build
cd build
cmake ..
```

Finally you need the runtime scene binary files and textures. These can be downloaded under [releases](https://github.com/marcusnessemadland/mge-demo/releases)

Copy and Paste the runtime folder in the mge-demo directory and build the project.

[License (Apache 2)](https://github.com/marcusnessemadland/mge/blob/main/LICENSE)
-----------------------------------------------------------------------

<a href="http://opensource.org/license/apache-2-0" target="_blank">
<img align="right" src="https://opensource.org/wp-content/uploads/2022/10/osi-badge-dark.svg" width="100" height="137">
</a>

	Copyright 2025 Marcus Nesse Madland
    
	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
