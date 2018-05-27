# zephyr

*Zephyrus, sometimes known in English as just Zephyr, is the Greek god of the west wind. The gentlest of the winds, Zephyrus is known as the fructifying wind, the messenger of spring.*

## Setup and working

### Second setup

- The Second Setup is the first baby step in achieving *zephyr*'s goal of controlling a target device.
- Conections remain same as First setup. [Refer](documentation/Components-and-Connections.md) for connecting the components.
- Flash [code](arduino/deviceCode.ino) to the Arduino Board.
- Open the `Serial Monitor` to pass single characters to the board and toggle the Device. 
- The character `o` will switch on the device. Rest all characters will switch it off.

#### NOTE:
- Be careful with the setup since it deals with High Voltage Supply
- It is adviced to connect the power supply only after all the connections are made.
- The deviceCode uses Digital Pin 7 to control the relay. In case you would like to use a different PIN, make the connections and update the code accordingly.
