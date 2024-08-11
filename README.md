# Password_Maker
A gadget that generates complex passwords locally.

[English](README.md) • [中文](README_ZH.md)

# About
This program can be used to generate complex passwords, and using the same parameters will give the same password, so it can also be used to record passwords.
This program is installed on the surface, runs entirely locally, does not obtain or upload any data, only generates a configuration file locally, and the file is unique (if the same parameters are used, it is the same and can be used to migrate the software).
This program generates passwords based on the class hashing algorithm, and does not store the results and their generation parameters, but when using command calls, please pay attention to the command records clearly to avoid leaking the generated parameters.

# Using
This program supports direct startup and command invocation.
Example command:<br>
`./Password_Maker.exe Platform_Name Account_Name AA1111111111A !<`

## parameters
This program supports the use of additional parameters to control the generation effect:

Parameters can be contained in the program file name, and when invoked using a command, the control parameter is in the fourth parameter.
The argument invoked by the command will override the filename parameter.

Parameter|Eexplain
----|----
!|Disable character. If you limit multiple characters, use the ! before each character.
+<br>Poewr<br>Plus|Enable the enhanced mode to expand the generated character capacity and obtain higher password complexity.
Weighted<br>Balanced|If the weighting algorithm is enabled, the selection of character types will receive a bonus to the total number of characters of that type, so as to achieve a balance of type allocation.
Local|If the localization mode is enabled, the password will be changed after the software is migrated to a different directory, so please use it carefully.
Reset|Reset.
?<br>Help|Displays help information.

## Tricks
You can deploy the program to a specified location, rename it, add parameters to the file name, and then create a shortcut.
Use the shortcut to directly call the corresponding generation parameters.
