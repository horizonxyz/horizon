# HorizonXYZ/Horizon

[![MSVC](https://img.shields.io/github/actions/workflow/status/horizonxyz/horizon/cmake.yml?label=MSVC&logo=visual-studio)](https://github.com/horizonxyz/horizon/actions/workflows/cmake.yml?job=Windows-MSVC-ALL-ASAN)
[![GCC](https://img.shields.io/github/actions/workflow/status/horizonxyz/horizon/cmake.yml?label=GCC&logo=gnu)](https://github.com/horizonxyz/horizon/actions/workflows/cmake.yml?job=Debian-GCC-ALL-ASAN)
[![CLANG](https://img.shields.io/github/actions/workflow/status/horizonxyz/horizon/cmake.yml?label=Clang&logo=llvm)](https://github.com/horizonxyz/horizon/actions/workflows/cmake.yml?job=Debian-CLANG-ALL-ASAN)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
![Repo Size](https://img.shields.io/github/repo-size/horizonxyz/horizon.svg)
![Contributors](https://img.shields.io/github/contributors/horizonxyz/horizon)

[![CMake](https://img.shields.io/badge/CMake-3.17-blue?logo=cmake)](https://cmake.org/) [![C++](https://img.shields.io/badge/C++-17-blue?logo=c%2B%2B)](https://isocpp.org/) [![Lua](https://img.shields.io/badge/Lua-5.4-blue?logo=lua)](https://www.lua.org/) [![MySQL](https://img.shields.io/badge/MySQL-8.0-blue?logo=mysql&logoColor=white)](https://www.mysql.com/) [![Boost](https://img.shields.io/badge/Boost-1.69.0-blue)](https://www.boost.org/) [![Readline](https://img.shields.io/badge/Readline-8.1-blue?logo=gnu)](https://tiswww.case.edu/php/chet/readline/rltop.html) [![sol2](https://img.shields.io/badge/sol2-3.2.3-blue.svg)](https://github.com/ThePhD/sol2)

HorizonXYZ/Horizon is a robust and versatile C++ project designed to supersede older Ragnarok Online emulators, namely from the eAthena family. 

<img src="https://i.imgur.com/x1wyrJA.gif" width="100%" height="100%">

## Table of Contents

- [Why Horizon](#why-horizon)
- [Showcase](#showcase)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Why Horizon?
### 1. Customizability and Extended Functionality

Built with the need for more customizability in mind, Horizon offers a comprehensive solution for the extended functionality of RO features such as the following, through the use of Lua (our scripting language) :

- Skills
- Status Effects
- Combat and damage components
- In-game **At-commands**
- Development oriented **Script-commands** 
- Server Administration based **Console-commands**
- Game Administration based **Web-commands**

### 2. High Performance and Maintainability

The project leverages advanced C++ features and OOP design principles and follows best coding practices to ensure high performance and maintainability. Each feature in the project is carefully designed with software design principles such as -

- [SOLID](https://en.wikipedia.org/wiki/SOLID)
- [KISS](https://en.wikipedia.org/wiki/KISS_principle)
- [YAGNI](https://en.wikipedia.org/wiki/You_aren%27t_gonna_need_it)

### 3. Features

It includes a variety of features such as a -

- Multithreaded infrastructure
- Packet-based networking system
- Database Support
- Lua scripting engine
- Console interface

making it a go-to choice for server owners that want a modern industry-standard solution for their RO server. It is aimed to be a high-end solution for RO server owners catering to larger user populations, allowing a seamless and uninterrupted support of thousands of players at once.

### 4. Flexibility

Whether you're looking to build a small server that offers a variety of customizations, or a large one, HorizonXYZ/Horizon provides the tools and flexibility you need to achieve your goals.

### 5. Open Source

The project is open-source and encourages contributions from developers who are interested in enhancing its capabilities and reach.

## Showcase
Here are some videos showcasing the project:
### Combat Damage System Test / Damage Delay Test / Walk Delay Test
[![HorizonXYZ/Horizon: Combat Damage System Test / Damage Delay Test / Walk Delay Test](http://img.youtube.com/vi/LlA1fUt6NfU/0.jpg)](http://www.youtube.com/watch?v=LlA1fUt6NfU "HorizonXYZ/Horizon: Combat Damage System Test / Damage Delay Test / Walk Delay Test")
### Item Drop Test
[![HorizonXYZ/Horizon: Item Drop Test](http://img.youtube.com/vi/wcsBmldvGDI/0.jpg)](http://www.youtube.com/watch?v=wcsBmldvGDI "HorizonXYZ/Horizon: Item Drop Test")
### Skill System Test
[![HorizonXYZ/Horizon: Skill System Test](http://img.youtube.com/vi/U1ZF9-QDtZM/0.jpg)](http://www.youtube.com/watch?v=U1ZF9-QDtZM "HorizonXYZ/Horizon: Skill System Test")
### Storage / Premium Storage System Test
[![HorizonXYZ/Horizon: Storage / Premium Storage System Test](http://img.youtube.com/vi/3ctNApHIFE4/0.jpg)](http://www.youtube.com/watch?v=3ctNApHIFE4 "HorizonXYZ/Horizon: Storage / Premium Storage System Test")

## Getting Started

To get a local copy up and running, follow these steps:

### Prerequisites

  - git
  - g++ or clang (version 4.5 or newer, recommended 5.0 or newer)
  - [CMake 3.7+](https://cmake.org/)
  - [Boost v1.60+](https://www.boost.org/)
  - [Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
  - [Sol2](https://github.com/ThePhD/sol2)
  - Mysql
  - Mysql Connector C++

### Hardware
#### Minimum
|| Windows  | Linux  |
|---|---|---|
|RAM For Compiling| 4096MB  | 1024MB   |
|RAM For Running| 2048MB  | 2048MB  |
|CPU| 2 Cores | 1 Core |
#### Recommended
|| Windows  | Linux  |
|---|---|---|
|RAM For Compiling| 8192MB  | 2048MB   |
|RAM For Running| 4096MB  | 4096MB  |
|CPU| 4 Cores | 2 Cores |
### Installation

- Read the [Windows Installation Guide](https://github.com/horizonxyz/horizon/wiki/How-to-install-Horizon-on-Windows-11)
- Read the [Linux Installation Guide](https://github.com/horizonxyz/horizon/wiki/Installation-on-Linux---Debian)

## Usage

After compiling and setting up the project, you can start the servers with the following command:

```bash
auth.exe --with-config="config/auth-server.lua"
char.exe --with-config="config/char-server.lua"
zone.exe --with-config="config/zone-server.lua"
```

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## License

Distributed under the GNU General Public License v3.0. See `LICENSE` for more information.

## Acknowledgements
- [C++](http://www.cplusplus.com/)
- [Lua](https://www.lua.org/)
- [MySQL](https://www.mysql.com/)
- [Sephus](https://github.com/sagunkho)
- [All Contributors](https://github.com/horizonxyz/horizon/contributors)
