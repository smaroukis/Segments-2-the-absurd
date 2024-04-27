
## Overview

- Build process is via the Makefile using the `arm-none-eabi-gcc` version as installed via the STM32 command line tools 
- Firmware upload & Debuggin is done viaOpenOCD over STLink (transport interface SWD by default?)

Commands:
- Build & Flash at same time via VSCode (`CMD+SHIFT+B`) → Makefile (i.e. `make flash`) → OpenOCD 

## Important files / changes for use

GCC path: is hardcoded and not in system environment variables, but is mainly used in 
- `tasks.json` in the `GCC_PATH` environment variable when we call `make`
- for Intelliense in `c_cpp_properties.json` (for the C/C++ Extension from Microsoft)

Other things to edit
- include paths & define's in the `c_cpp_properties.json`, currently not in use but an example can be found in `c_cpp_properties_old.json` (I think this just affects Intellisense and not compilation)

## Development

(Note currently just using direct commits to `tm1637` `main` branch of submodule)

Due to using submodule (`ThirdParty/tm1637`), development process is as follows
- commit and push and changes for the submodule _before_ commiting changes for the parent
- once submodule changes are pushed, in the project root run `git add ThirdParty/tm1637` (no need for `git fetch`) to add the submodule changes (commit hash should be changed)
- develop, stage, and push changes in the parent project as normal

Tip use
`git submodule status` to see the commit we are pointing to
and compare it to:
```
cd path/to/submodule
git log -1
```


