For now, see <https://maroukis.net/sev-seg> 

> [!CAUTION] You will need to run a `git submodule init && git submodule update` to pull in changes to the TM1637 Seven Segment driver submodule code

## Building 
In the MCU directory i.e. `src/stm32` run `make flash`, see Makefile and VSCode `tasks.json` for details.

## Dependencies
- a forked version of nimaltd/tm1637 as a submodule in src/.../ThirdParty/tm1637 

Update the submodule _within the submodule directory_:
- `git fetch` && `git merge upstream/main`