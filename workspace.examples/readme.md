# RTG4 Development Kit Mi-V Sample Designs for Libero v12.3

Sample Mi-V Libero Projects for the RTG4 Radiation-Tolerant Development Kit.

## <a name="quick"></a> Quick Instructions

### Checkout The Code
#### Running in batch mode (Ubuntu 18.04)
    $ git clone https://github.com/CLappin/RTG4-Development-Kit/tree/develop/
    $ cd RTG4-Development-Kit
    $ # Output will be seen on the terminal window.
    $ libero "SCRIPT_ARGS:<RTG4_DEV_KIT.tcl AHB>"

#### Running in GUI mode (Ubuntu 18.04 and Windows 10)
    $ git clone https://github.com/CLappin/RTG4-Development-Kit/tree/develop/

    1. Open Libero SoC v12.3.
    2. Execute the script, Project -> Execute Script.
    3. Select the directory that the script is located in using the "...".
    4. Select the script and select "Open".
    5. In the arguments text box "AHB".
    6. Select the "Run" icon.
    7. Once complete, a script report will generated.

## <a name="Script arguments"></a> Script Arguments
The valid first arguements are: 
| Arguement    |  Description   |
| ------------- |:-------------:|
| AHB      | Generate a sample design with the MiV_RV32IMA_L1_AHB |
| AXI      | Generate a sample design with the MiV_RV32IMA_L1_AXI |

The valid second arguments are:
| Arguement    |  Description   |
| ------------- |:-------------:|
| SYNTHESIS | Run synthesis on the design  |
| PLACE_AND_ROUTE | Run place and route on the design  |
| GENERATE_BITSTREAM | Generate the bitstream of the design|
| EXPORT_PROGRAMMING_FILE | Export the programming file |
  
