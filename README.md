# Openframeworks Experiments
I have configured each project so it can be builded from **VS Code** *(Ctrl + Shift + B by default)*.

### To configure the make process:
In the file **Makefile**, change the **OF_ROOT** value with yours:

```bash
OF_ROOT=$(realpath [YOUR_OF_PATH])
```

### To configure the C++ intellisense:
Install the C++ extension and, in the file **.vscode/c_pp_properties.json**, change all my OF paths **/home/jerson/openframeworks/** with your custom OF installation path.